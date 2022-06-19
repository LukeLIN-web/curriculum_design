这是我最开始的课程仓库

经过漫长修改, 目前只剩下非cs课的一些笔记.

#### git 笔记
使用git fecth方法将远程仓库项目更新到本地仓库用于开发

   ``` Bash
 git remote -v   
 git fetch origin master:temp
 git diff temp
 git merge temp
 git br -d temp
   ```

pull = fetch + merge ,多人协作时不够安全

在window下生成ssh密钥,然后加在github上. https://www.jianshu.com/p/2790a860f151

怎么删除git中一个无用的分支:

切换默认分支, 然后删除. 



<u>工作区搞错了之后</u>

先 git status 看一看.令`git checkout -- readme.txt`意思就是，把`readme.txt`文件在工作区的修改全部撤销，这里有两种情况：

一种是`readme.txt`自修改后还没有被放到暂存区，现在，撤销修改就回到和版本库一模一样的状态；

 

一种是`readme.txt`已经添加到暂存区后，又作了修改，现在，撤销修改就回到添加到暂存区后的状态。

总之，就是让这个文件回到最近一次`git commit`或`git add`时的状态。

事实上git restore 撤销修改回到添加到暂存区后的状态比较常用, checkout 用来切换分支比较多, checkout功能比较多,图书馆里借出书也叫checkout.

<u>如果clone下来,直接push失败</u>

原因：
1.如果创建远程仓库的时候，没有勾选创建 README.md 的情况：暂存区还没有任何内容就向远程库进行提交，空的暂存区时不能提交上去的，需要至少有一次 add  和 commit
2.如果创建远程仓库的的时候，勾选了创建 README.md 的情况：github 中的 README.md 文件不在本地代码目录中

<u>branch不显示分支</u>

因为git的分支必须指向一个commit，没有commit就没有任何分支，提交一个commit后就会自动创建master分支



<u>fatal: HttpRequestException encountered.发送请求时出错</u>

可是在每次push  的时候，都要输入用户名和密码，很是麻烦

原因是使用了https方式 push

 fatal: Could not read from remote repository

用 git clone XX 命令从git上下拉代码时，也出现报这个错误，可是我明明ssh key已经配好了，为什么还会出现这样的事呢



看看 本地commit 两次, push 一次, GitHub算几次?

算两次, 所以本地多commit 就行,不用每天push. 写完一个逻辑就可以commit .



##### rebase和merge

例如现有上游分支 master，基于 master 分支拉出来一个开发分支 dev，在 dev 上开发了一段时间后要把 master 分支提交的新内容更新到 dev 分支，此时切换到 dev 分支，使用 `git rebase master`

等 dev 分支开发完成了之后，要合并到上游分支 master 上的时候，切换到 master 分支，使用 `git merge dev`



##### git 本地push 和远程不一致

我想换一个目录来连接远程的仓库, 不要用现在这个目录

远程master的代码是**无用的**并且可以使用**强推**

```bash
//添加仓库
git remote add origin <仓库地址>
//强制push本地master分支到远端的master分支
git push origin master:master -f
```

不能使用代码强推

```bash
//添加仓库
git remote add origin <仓库地址>
//关联远端master分支
git branch --set-upstream-to=origin/master master
//rebase 远端代码到本地(这会对本地代码进行变基，把远端的提交插入本地代码提交的最底下。好比房子的地基改变了，这个地基会和远端仓库的提交一致，本地的提交都变动到这些提交上面)
git rebase
//push代码
git push
```



