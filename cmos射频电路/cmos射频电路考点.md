40 平时分， 平时作业。



### Lec1

4月19日

第一个， 无线通讯

接收机， 发射机。

无线通讯， 震荡频率可以到100G， 几百个G。

不可能六边形

wifi功率不用很大， 因为距离近。



#### 非线性



手机信号是6uV， 





## Lec2

差分电路可以消除二阶效应. 但是不能消除三阶效应.

你的谐波会干扰别人的频段.

对于一个射频放大器而已, alpha 3 通常都小于0.  对于非线性系统而言, 都是compressive, 没有expansive. 射频很难就是, 噪声很大, 功率很大. 

#### 1dB压缩点

Gain Compression: 1-dB Compression Point

过了这个点， 电路就不工作在线性了 。

今天的第一个指标.非常重要的指标. **lec2 PPT 16页**

放大10个dB, 输入-100dB 输出-90d B, 但是不能永远按这个倍数. 

因为晶体管三阶效应的影响. 



#### cross modulation 

还有一个叫inter modulation

PPT27页，

alpha1是怎么算的？

调频调幅调相，对抗干扰的能力都不一样。



一个 900-MHz GSM 发射器向天线提供 1 W 的功率。信号的二次谐波必须被抑制（过滤）多少才能使 P1dB = -25 dBm 的 1.8 GHz 接收器不敏感？假设接收器距离 1 m，并且 1.8 GHz 信号在此距离传播时衰减 10 dB。

答案:

```
900 MHz 的输出功率等于 +30 dBm。衰减 10 dB 时，发射器天线处的二次谐波不得超过 -15 dBm，使其低于接收器的 P1dB。因此，二次谐波必须至少比 TX 输出的基波低 45 dB。在实践中，这种干扰必须再低几个 dB，以确保 RX 不会压缩。
```



#### 双音测试

频谱仪x轴就是频率，纵轴就是能量。

读取能量情况获得比值，测一个获得alpha1， 可以计算出alpha3.

#### IP3

 三阶intercept point

输入信号幅度不断增大， 衰减会越来越严重，在这个点， 三阶和一阶相等， 不再放大。

IIP3 ， 输入 三阶intercept point。实际上做不到， 因为电路早就饱和了。

IP3 is not a directly measureable quantity, but a point obtained by extrapolation



ppt 45页。 热噪声。

噪声大小， 要功率密度 * 信号带宽。

白噪声， 所有频率上都一样。



热噪声， 我们能做的很少。

我们能改变他的工作条件。



#### 考点 noise figure

PPT60页， 

怎么计算noise figure？

SNRin/SNRout= noise figure

#### 级联的NF

不用推导， 记住结论。     后面几项分母越来越大， 值越来越小，  第二级要除以第一级的增益，  所以噪声系数在前面的更重要， 前面的级和后面的级有抑制作用。 
所以第一级是low noise 放大器， 这样抑制后面的噪声有积极的作用。





#### 灵敏度

PPT68页。

灵敏度定义为接收器能够以“可接受的质量”检测到的最小信号电平。

-174dBm/Hz 是噪声的底，要记下来。

NF是哪里来的？  是噪声图

10log B是带宽的带长。  信号只在一定带宽内， 所以外面的和他无关。

SNRmin是能检测到的最小长度。





### 

### lec4

噪声的底 -174. 4KTRs， Rs是天线的电阻。

电压是20log， 功率是10log。

系统指标：

Dynamic Range:
     Maximum tolerable desired signal power divided by the minimum tolerable desired signal power 

SFDR:
     Lower end equal to sensitivity.
     Higher end defined as maximum input level in a two-tone test for which the third-order IM products do not exceed the integrated noise of the receiver



品质因子：

S参数的定义

S11       越小越好



S22 越小越好， 和S11对称。



要让阻抗是匹配的， 

这个不用讲， 不考
 非线性系统



### lec5 

##### 三个效率

可探测性Detectability：在给定的信道衰减attenuation和接收机噪声量下，解调信号的质量。
带宽效率Bandwidth Efficiency：在基带信号中给定的信息速率下，被调制的载波所占用的带宽。

调制效率太低， 带宽利用率会很低。比如11，10，00 比1 和0 效率更高。PAM4

功率效率Power Efficiency：发射器中可使用的功率放大器（PA）的类型  。 

基本上所有的功耗都在功耗放大器上。

wifi中最主流的是QAM 



TDD， FDD， 各有优缺点， 不详细讲。

要关注的一些指标：

##### 频带

ISM给的免费的频段都不好， 5.1-5.8GHz 免费， 58-67GHz 免费现在60GHz以上都没有推广，高频衰减太快。做了几十年也没有做好。30GHz的频段比较好，一般给雷达用。

数据速率

天线duplexing method

调制类型

TX输出功率

TX EVM和频率mask

RX sensitivity

RX 动态范围

RX tolerance to blocks 抗干扰能力。

