**HTTP就是一个用文本格式描述报文头并用双换行分隔报文头和内容，在TCP基础上实现的请求-响应模式的双向通信协议。**

Uniform resource location 不仅标识资源。而且指明如何locate这个资源。

http：// 端口80 

https：// 端口443

https 运行在 ssl和tls 上， ssl/tls运行在tcp上。



1xx  信息性状态码, 正在处理

2xx 成功

3xx 重定向, 比如 资源移动到其他url

4xx 客户端错误,  404 

5xx 服务器错误.





### http加密

**加密用对称加密， 密钥用服务器方的证书进行了非对称性加密。**

非对称加密总是和对称加密一起使用。假设小明需要给小红需要传输加密文件，他俩首先交换了各自的公钥，然后：

1. 小明生成一个随机的AES口令，然后用小红的公钥通过RSA加密这个口令，并发给小红；
2. 小红用自己的RSA私钥解密得到AES口令；
3. 双方使用这个共享的AES口令用AES加密通信。

可见非对称加密实际上应用在第一步，即加密“AES口令”。这也是我们在浏览器中常用的HTTPS协议的做法，即浏览器和服务器先通过RSA交换AES口令，接下来双方通信实际上采用的是速度较快的AES对称加密，而不是缓慢的RSA非对称加密。 

服务器资源。

- 对称加密：密钥只有一个，加密解密为同一个密码，且加解密速度快，典型的对称加密算法有DES data encryption standard 、AES     advanced encryption standard等；
- 非对称加密：密钥成对出现（且根据公钥无法推知私钥，根据私钥也无法推知公钥），加密解密使用不同密钥（公钥加密需要私钥解密，私钥加密需要公钥解密），相对对称加密速度较慢，典型的非对称加密算法有RSA三个人的姓氏、DSA Digital Signature Algorithm等。

#### 数字签名

如果使用私钥加密，公钥解密是否可行呢？实际上是完全可行的。

不过我们再仔细想一想，私钥是保密的，而公钥是公开的，用私钥加密，那相当于所有人都可以用公钥解密。这个加密有什么意义？

这个加密的意义在于，如果小明用自己的私钥加密了一条消息，比如`小明喜欢小红`，然后他公开了加密消息，由于任何人都可以用小明的公钥解密，从而使得任何人都可以确认`小明喜欢小红`这条消息肯定是小明发出的，其他人不能伪造这个消息，小明也不能抵赖这条消息不是自己写的。

因此，私钥加密得到的密文实际上就是数字签名，要验证这个签名是否正确，只能用私钥持有者的公钥进行解密验证。使用数字签名的目的是为了确认某个信息确实是由某个发送方发送的，任何人都不可能伪造消息，并且，发送方也不能抵赖。DSA是Digital Signature Algorithm的缩写，它使用ElGamal数字签名算法。

DSA只能配合SHA使用，常用的算法有：

- SHA1withDSA
- SHA256withDSA
- SHA512withDSA

和RSA数字签名相比，DSA的优点是更快。



### 请求协议

```http
GET或POST 请求的url路径（一般是去掉域名的路径） HTTP协议版本号
字段1名: 字段1值\r\n
字段2名: 字段2值\r\n
      ...
字段n名 : 字段n值\r\n
\r\n
http协议包体内容
```

eg:浏览器组装的http数据包格式如下： 

```http
GET /index_2013.php HTTP/1.1\r\n
Host: www.hootina.org\r\n
Connection: keep-alive\r\n
Upgrade-Insecure-Requests: 1\r\n
User-Agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3325.146 Safari/537.36\r\n
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\n
Accept-Encoding: gzip, deflate\r\n
Accept-Language: zh-CN,zh;q=0.9,en;q=0.8\r\n
\r\n
```

这里只有head,get 一般没有package body  



### 应答协议

给客户端的应答协议与http请求协议有一点点差别，就是将请求的url路径换成所谓的http响应码，如200表示应答正常返回、404页面不存在。应答协议格式如下：

```http
GET或POST 响应码 HTTP协议版本号
字段1名: 字段1值\r\n
字段2名: 字段2值\r\n
      ...
字段n名 : 字段n值\r\n
\r\n
http协议包体内容
```

注册结果放在retData中，为了发给客户端，我们将结果中的特殊字符如双引号转码，如返回结果是：

```text
{"code":0, "msg":"ok"}
```

会被转码成：

```http
{%22code%22:0,%20%22msg%22:%22ok%22}
```

不满足一个http包头时的处理，如果某个客户端（不是使用浏览器）通过程序模拟了一个连接请求，但是迟迟不发含有\r\n\r\n的数据，这路连接将会一直占用。我们可以判断收到的数据长度，防止别有用心的客户端给我们的服务器乱发数据。我们假定，我们能处理的最大url长度是2048，如果用户发送的数据累积不含\r\n\r\n，且超过2048个，我们认为连接非法，将连接断开。

如果一个客户端连上来不给我们发任何数据，这段逻辑就无能为力了。如果不断有客户端这么做，会浪费我们大量的连接资源，所以我们还需要一个定时器去定时检测哪些http连接超过一定时间内没给我们发数据，找到后将连接断开, connection reset。这又涉及到服务器定时器如何设计了，关于这部分请参考我写的其他文章。链接：https://zhuanlan.zhihu.com/p/37198392

### http怎么分割

这里有三个变量，分别是username、password和appid，他们之间使用&符号分割，但是请注意的是，这不意味着传递多个POST变量时必须使用&符号分割，只不过这里是浏览器html表单（输入用户名和密码的文本框是html表单的一种）分割多个变量采用的默认方式而已。你可以根据你的需求，来自由定制，只要让服务器知道你的解析方式即可。

如上图所示，由于http协议是基于tcp协议的，tcp协议是流式协议，包头部分可以通过多出的\r\n来分界，包体部分如何分界呢？这是协议本身要解决的问题。目前一般有两种方式，第一种方式就是在包头中有个content-Length字段，这个字段的值的大小标识了POST数据的长度，上图中55就是数据username=balloonwj%40qq.com&password=iloveyou&appid=otn的长度，服务器收到一个数据包后，先从包头解析出这个字段的值，再根据这个值去读取相应长度的作为http协议的包体数据。还有一个格式叫做http chunked技术（分块），大致意思是将大包分成小包



### cookie与session

cookie 的出现是因为 HTTP 是无状态的一种协议，换句话说，服务器记不住你，可能你每刷新一次网页，就要重新输入一次账号密码进行登录。这显然是让人无法接受的，cookie 的作用就好比服务器给你贴个标签，然后你每次向服务器再发请求时，服务器就能够 cookie 认出你。

抽象地概括一下：**一个 cookie 可以认为是一个「变量」，形如 `name=value`，存储在浏览器；一个 session 可以理解为一种数据结构，多数情况是「映射」（键值对），存储在服务器上**。

注意，我说的是「一个」cookie 可以认为是一个变量，但是服务器可以一次设置多个 cookie，所以有时候说 cookie 是「一组」键值对儿，这也可以说得通。

cookie 可以在服务器端通过 HTTP 的 SetCookie 字段设置 cookie，比如我用 Go 语言写的一个简单服务：

```go
func cookie(w http.ResponseWriter, r *http.Request) {
    // 设置了两个 cookie 
    http.SetCookie(w, &http.Cookie{
        Name:       "name1",
        Value:      "value1",
    })

    http.SetCookie(w, &http.Cookie{
        Name:  "name2",
        Value: "value2",
    })
    // 将字符串写入网页
    fmt.Fprintln(w, "页面内容")
}
```

当浏览器访问对应网址时，通过浏览器的开发者工具查看此次 HTTP 通信的细节，可以看见服务器的回应发出了两次 `SetCookie` 命令：

在这之后，浏览器的请求中的 `Cookie` 字段就带上了这两个 cookie：

**cookie 的作用其实就是这么简单，无非就是服务器给每个客户端（浏览器）打的标签**，方便服务器辨认而已。当然，HTTP 还有很多参数可以设置 cookie，比如过期时间，或者让某个 cookie 只有某个特定路径才能使用等等。

但问题是，我们也知道现在的很多网站功能很复杂，而且涉及很多的数据交互，比如说电商网站的购物车功能，信息量大，而且结构也比较复杂，无法通过简单的 cookie 机制传递这么多信息，而且要知道 cookie 字段是存储在 HTTP header 中的，就算能够承载这些信息，也会消耗很多的带宽，比较消耗网络资源。

session 就可以配合 cookie 解决这一问题，比如说一个 cookie 存储这样一个变量 `sessionID=xxxx`，仅仅把这一个 cookie 传给服务器，然后服务器通过这个 ID 找到对应的 session，这个 session 是一个数据结构，里面存储着该用户的购物车等详细信息，服务器可以通过这些信息返回该用户的定制化网页，有效解决了追踪用户的问题。

**session 是一个数据结构，由网站的开发者设计，所以可以承载各种数据**，只要客户端的 cookie 传来一个唯一的 session ID，服务器就可以找到对应的 session，认出这个客户。

当然，由于 session 存储在服务器中，肯定会消耗服务器的资源，所以 session 一般都会有一个过期时间，服务器一般会定期检查并删除过期的 session，如果后来该用户再次访问服务器，可能就会面临重新登录等等措施，然后服务器新建一个 session，将 session ID 通过 cookie 的形式传送给客户端。

那么，我们知道 cookie 和 session 的原理，有什么切实的好处呢？**除了应对面试，我给你说一个鸡贼的用处，就是可以白嫖某些服务**。

### **session 的实现**

session 的原理不难，但是具体实现它可是很有技巧的，一般需要三个组件配合完成，它们分别是 `Manager`、`Provider` 和 `Session` 三个类（接口）。

![img](https://pic3.zhimg.com/v2-df2744e78cc28dae0f5e2e15dfb7baf2_b.jpg)

1、浏览器通过 HTTP 协议向服务器请求路径 `/content` 的网页资源，对应路径上有一个 Handler 函数接收请求，解析 HTTP header 中的 cookie，得到其中存储的 sessionID，然后把这个 ID 发给 `Manager`。

2、`Manager` 充当一个 session 管理器的角色，主要存储一些配置信息，比如 session 的存活时间，cookie 的名字等等。而所有的 session 存在 `Manager` 内部的一个 `Provider` 中。所以 `Manager` 会把 `sid`（sessionID）传递给 `Provider`，让它去找这个 ID 对应的具体是哪个 session。

3、`Provider` 就是一个容器，最常见的应该就是一个散列表，将每个 `sid` 和对应的 session 一一映射起来。收到 `Manager` 传递的 `sid` 之后，它就找到 `sid` 对应的 session 结构，也就是 `Session` 结构，然后返回它。

4、`Session` 中存储着用户的具体信息，由 Handler 函数中的逻辑拿出这些信息，生成该用户的 HTML 网页，返回给客户端。

那么你也许会问，为什么搞这么麻烦，直接在 Handler 函数中搞一个哈希表，然后存储 `sid` 和 `Session` 结构的映射不就完事儿了？

**这就是设计层面的技巧了**，下面就来说说，为什么分成 `Manager`、`Provider` 和 `Session`。

先从最底层的 `Session` 说。既然 session 就是键值对，为啥不直接用哈希表，而是要抽象出这么一个数据结构呢？

第一，因为 `Session` 结构可能不止存储了一个哈希表，还可以存储一些辅助数据，比如 `sid`，访问次数，过期时间或者最后一次的访问时间，这样便于实现想 LRU、LFU 这样的算法。

第二，因为 session 可以有不同的存储方式。如果用编程语言内置的哈希表，那么 session 数据就是存储在内存中，如果数据量大，很容易造成程序崩溃，而且一旦程序结束，所有 session 数据都会丢失。所以可以有很多种 session 的存储方式，比如存入缓存数据库 Redis，或者存入 MySQL 等等。

因此，`Session` 结构提供一层抽象，屏蔽不同存储方式的差异，只要提供一组通用接口操纵键值对：

```text
type Session interface {
    // 设置键值对
    Set(key, val interface{})
    // 获取 key 对应的值
    Get(key interface{}) interface{}
    // 删除键 key
    Delete(key interface{})
}
```

再说 `Provider` 为啥要抽象出来。我们上面那个图的 `Provider` 就是一个散列表，保存 `sid` 到 `Session` 的映射，但是实际中肯定会更加复杂。我们不是要时不时删除一些 session 吗，除了设置存活时间之外，还可以采用一些其他策略，比如 LRU 缓存淘汰算法，这样就需要 `Provider` 内部使用哈希链表这种数据结构来存储 session。

PS：关于 LRU 算法的奥妙，参见前文「LRU 算法详解」。

因此，`Provider` 作为一个容器，就是要屏蔽算法细节，以合理的数据结构和算法组织 `sid` 和 `Session` 的映射关系，只需要实现下面这几个方法实现对 session 的增删查改：

```text
type Provider interface {
    // 新增并返回一个 session
    SessionCreate(sid string) (Session, error)
    // 删除一个 session
    SessionDestroy(sid string)
    // 查找一个 session
    SessionRead(sid string) (Session, error)
    // 修改一个session
    SessionUpdate(sid string)
    // 通过类似 LRU 的算法回收过期的 session
    SessionGC(maxLifeTime int64)
}
```

最后说 `Manager`，大部分具体工作都委托给 `Session` 和 `Provider` 承担了，`Manager` 主要就是一个参数集合，比如 session 的存活时间，清理过期 session 的策略，以及 session 的可用存储方式。`Manager` 屏蔽了操作的具体细节，我们可以通过 `Manager` 灵活地配置 session 机制。



### GET和POST

1. get数据添加在url后面,`url`长度有限制,上传的数据量很小,而且暴露用户名和密码,  post是用附件, 数据量更大.

