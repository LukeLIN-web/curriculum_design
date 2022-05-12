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

不仅取决于所考虑的电路的噪声，而且取决于前级提供的信噪比
如果输入信号不含噪声，NF=∞

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





### lec4

噪声的底 -174. 4KTRs， Rs是天线的电阻。

电压是20log， 功率是10log。

##### 系统指标

##### 动态范围

​     可容忍的最大期望信号功率除以可容忍的最小期望信号功率 

Dynamic Range:
     Maximum tolerable desired signal power divided by the minimum tolerable desired signal power 

##### SFDR

​     Lower end equal to sensitivity.
​     Higher end defined as maximum input level in a two-tone test for which the third-order IM products do not exceed the integrated noise of the receiver

​      毛刺情况下的动态范围, 下端等于灵敏度。
​     高端定义为双音测试中的最大输入电平，其中三阶IM产品不超过接收器的集成噪声。 SFDR大于DR

#### 品质因子

Passive Impedance Transformation: Quality Factorndicates how close to ideal an energy-storing device is.被动阻抗转换。品质系数表示一个储能设备有多接近理想。

振荡器里面有电阻,  希望品质因子越大越好, 串联希望电阻小, 并联希望电阻大,  为什么? 损耗小，希望并联电流全部从电容走过，串联就电阻小点

##### 电阻和电容

串联, 电容是虚部,  虚部的阻抗/ 实部的阻抗,  如果都在虚部上, 实部上很小, 那么品质因子就高. 

并联, 阻抗越小越好, 电阻越大并联起来越小. 

##### 电阻和电感

串联, 电感是高频的阻抗, 虚部,  虚部的阻抗/ 实部的阻抗,  如果都在虚部上, 实部上很小, 那么品质因子就高. 

并联, 阻抗越小越好, 电阻RP(人品)越大并联起来越小. 

##### 串联到并联的转换

不知道寄生电阻是串联还是并联. 所以有个等效, 可以看关系. 

电容基本不变, 并联电阻会变大, 是串联电阻的Q平方倍. 看进去的阻抗是不一样的。

当需要进行变化的时候，可以利用这个串并的转化来实现q的平方倍变化

为什么要这么做?经常需要做阻抗变化，特别是在高频的时候.

50 欧姆阻抗是大还是小? 不一定

要让阻抗是匹配的

#### 匹配网络

第一次作业problem1 , PPT  73页

假如RL太大,怎么变成小阻抗? 

放电阻RL在并联网络中, 加一个串联网络L1.

我的电容和电感在高频谐振的时候，电容和电阻是虚部抵消的, 留下实部. rs并不是一个真实的，是个等效的.

例题1:

设计上图的匹配网络，以便在中心频率为5GHz时将RL=50Ω转换为25Ω。

假设QP2 >> 1，我们有C1 = 0:90 pF和L1 = 1.13 nH，分别。然而，不幸的是，QP=1.41，表明QP2>>1的近似值不能使用。因此，我们得到C1 = 0:637 pF和L1 = 0:796 nH。

例题2 :

低阻到高阻. 

确定下图所示的电路是如何转换RL的。

我们推测，将L1-RL分支转换为并联部分会产生一个更高的电阻。如果QS2 = (L1ω/RL)2 >> 1，那么等效的并联电阻是

并联的等效电感大约等于L1，并被C1所抵消。





S参数的定义

S11       越小越好



S22 越小越好， 和S11对称。

不考 非线性系统



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

## lec6

线性度有哪些指标?

一阶, 二阶, 三阶.

线性度不好会如何?



接收机发射机, 会有哪些指标?

Heterodyne  Receivers

Problem of Image
Mixing Spurs
Sliding-IF RX



1. filter 要有高Q
2. 要有可变的,精确的中心频率

怎么做带通滤波器?

一个高通一个低通.

在全双工duplex标准中，TX和RX同时工作。
在1W的TX功率下，LNA感应到的泄漏可以达到-20dBm，这就决定了RX的压缩点要大大增加。

前端带选滤波器在其选择性和带内损耗之间存在权衡，因为带通频率响应的边缘只能通过增加滤波器的阶数来锐化。
前端损失直接提高了整个接收器的NF

例题1:解释一下LNA后面的带通滤波器如何缓解CDMA系统中的TX-RX泄漏。

答案:如下图所示，如果BPF在TX频段提供额外的抑制，那么RX链其他部分的线性度要求就会相应地放宽。然而，LNA的压缩点仍然必须足够高。



#### 接收机的构架

#### Basic Heterodyne Receivers

- "外差Heterodyne "接收机采用不等于ωin的LO频率，因此中频不为零。
- 一个执行下变频的混频器。
- 由于其高噪声，下变频混频器前有一个低噪声放大器

从载波搬到基带, 一种是直接到0, 一种是先到比较低的频率.

##### 镜像的问题

有干扰信号.找到理想的方案清除镜像:

最常见的方法是在混频器前加一个 "image抑制滤波器"
一个具有高image抑制的滤波器通常出现在LNA和混频器之间，这样LNA的增益就降低了滤波器对接收器噪声系数的贡献。
image reject滤波器所要求的线性度和选择性决定了无源的片外实现。

1. 超 外参接收机
2. image 抑制滤波器
3. I Q两路,
4. hartley 架构

##### Direct-Conversion Receivers

优点

- 没有image大大简化了设计过程
- 通道选择由片上低通滤波器完成
- 混合尖峰的数量大大减少

缺点

1. 高频的时候相移会放大
2. DC Offsets

DC Offsets

有限的带内LO漏电出现在LNA的输入端。与所需信号一起，这个成分被放大并与LO混合。
可能会使基带电路饱和，根本无法进行信号检测。

例题2:

一个直接转换接收器direct-conversion receiver包含了从LNA输入到每个混频器输出的30dB的电压增益，以及在混频器之后的基带阶段的另一个40dB的增益。如果LNA输入处的LO漏电等于-60 dBm，请确定混频器输出处和基带链输出处的偏移电压。

答案:

AV1=30dB是什么意思？如果一个正弦波V0 cos ωint被施加到LNA输入端，那么混频器输出端的基带信号Vbb cos(ωin - ωLO)t，其振幅由以下公式给出

因此，对于一个输入Vleak cos ωLOt, 
混频器输出的直流值等于

由于AV1=31.6，Vleak=（632/2）μV。
我们有Vdc = 10 mV。
再放大40dB。
 这个偏移量在基带输出处达到了1 V!

The dc offsets measured in the baseband I and Q outputs are often unequal. Explain why

答案

假设在LO的正交相位存在的情况下，LNA输入端的净LO泄漏表示为Vleak cos(ωLOt+Φleak )，其中Φleak来自于从每个LO相位到LNA输入的路径的相移，也是泄漏VLO cos ωLOt和VLO sinωLOt的总和。

LO泄漏通过LNA和每个混频器，经历一个额外的相移，Φckt，并乘以VLO cos ωLOt和VLO sin ωLOt。因此，直流分量由以下公式给出： 因此，两个直流偏移一般是不相等的。

##### 偏移消除

用C1电容, 偏移消除：高通滤波器
这样的网络也会在零频率附近去除一部分信号的频谱，引入符号间干扰

##### Flicker Noise

An 802.11g receiver exhibits a baseband flicker noise corner frequency of 200 kHz. Determine the flicker noise penalty

 fBW = 10 MHz, fc = 200 kHz, and hence



希尔伯特变换

The shift-by-90 ° operation is also called the “Hilbert transform”.

##### Hartley Architecture

If we shift I(t) or Q(t) by another 90 ° before adding them, the image may be removed.

另一个关键的缺点来自于R1和C1的绝对值的变化。

如果转换到中频的信号有很宽的带宽，那么RC-CR部分产生的另一个缺点就会表现出来。



低中频结构的另一个变体如下图所示，下变频信号被应用于信道选择滤波器和放大器，如同在直接转换接收器中一样。然后将结果数字化，并在求和之前在数字域中进行希尔伯特变换。 这是对模拟电路而言最简单的方法,采样率不需要特别高. 

 "on-off 键控"（OOK）调制是ASK的一个特例，载波振幅在零和最大之间切换。

当LO被二进制基带数据直接打开和关闭时（上图左），如果LO的波动足够大，PA也会经历相对完整的切换，并向天线提供OOK波形。上图（右）可以避免LO不容易被PLL控制的问题。

### lec7

SPICE : simulation program with integrated circuit Emphasis

#### 寄生电容

高频寄生电容会带来额外损耗.小电容不能被忽略.

Cgd, Cgs.

Cgs怎么计算不讲, 有个概念就行. 

#### 寄生电阻

电阻会影响品质因子. 

电感的品质因子怎么算?  品质因子 = 存储的能量/消耗的能量. 也就是虚部/ 实部

电感的虚部= omega l / R 

0.5欧姆的电阻, 会让品质因子降很多.

探针探测. 

#### 史密斯圆图

不需要会画, 需要会看.

作用: 阻抗匹配系数 , 50欧姆, 阻抗有实部有虚部, 20+10j , 30 + 20j, 哪个更接近?

需要计算反射系数. 

(20+10j - 50) / (20+10j +50) = (-30+10j)/(70+10j) 然后计算幅度和相位.

更直接的一种方法, 是直接告诉我反射系数.

反射系数的模越小, 反射越小, 

 圈上变化的是虚部和实部. 上面的虚部是正的, 是电感, 下面的是负的, 是电容.实部是电阻.

串联电感, 顺时针转, 并联电感, 逆时针转. 

同心圆上 , 反射系数相等.

## Chapter5

低噪声放大器

5.2 input matching 问题

5.3 LNA topologies 

5.4 Gain swithching

5.5 band switching

5.6 high IP2 LNAs

5.7 非线性计算.

### 5.1

1. 最重要的是noise figure.

连一根线NF就会变大很多.

增益可以抑制噪声, 所以LNF要有足够大的增益. 

2. 稳定性  讲了两秒
3.  线性度 讲了几秒
4. 带宽

带宽不能太大不能太小, 带宽大, 带内噪声太大, 而且制造困难,LC一般都是窄带.

band switching, 做两个非连续的两个带, 像开车换挡一样,

最简单的是common source. 不可能有50欧姆的输入阻抗.

有实部和虚部, 调整比例关系, 可能获得50欧姆.

负载端加电感有好处, 高频可以有增益.

Neutralization of CF by LF:

通过使用并联谐振，有可能在某些频率范围内 "中和 "CF的影响。
将在输入和输出端引入大量的寄生电容，并使性能下降。

尽量少用电感. 用电阻的方法,Noise Figure of CS Stage with Resistive Feedback 非常适合先进工艺

