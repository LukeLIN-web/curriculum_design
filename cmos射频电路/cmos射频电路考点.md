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

## lec6

线性度有哪些指标?

一阶, 二阶, 三阶.

线性度不好会如何?

接收机发射机, 会有哪些指标?

要窄带宽.

1. filter 要有高Q
2. 要有可变的,精确的中心频率

怎么做带通滤波器?

一个高通一个低通.

#### TX-RX泄露

在全双工duplex标准中，TX和RX同时工作。
在1W的TX功率下，LNA感应到的泄漏可以达到-20dBm，这就决定了RX的压缩点要大大增加。

前端带选滤波器在其选择性和带内损耗之间存在权衡，因为带通频率响应的边缘只能通过增加滤波器的阶数来锐化。
前端损失直接提高了整个接收器的NF

例题1:解释一下LNA后面的带通滤波器如何缓解CDMA系统中的TX-RX泄漏。

答案:如下图所示，如果BPF在TX频段提供额外的抑制，那么RX链其他部分的线性度要求就会相应地放宽。然而，LNA的压缩点仍然必须足够高。

接收机的构架

### 外差分接收机

Heterodyne  Receivers

Problem of Image
Mixing Spurs
Sliding-IF RX

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

### Direct-Conversion Receivers

A **direct-conversion receiver** (**DCR**), also known as **homodyne**, **synchrodyne**, or **zero-IF receiver**

第二种解决方法,  分为I路和Q路,

优点

- 没有image大大简化了设计过程
- 通道选择由片上低通滤波器完成
- 混合尖峰的数量大大减少

缺点

1. 高频的时候相移会放大
2. DC Offsets

##### DC Offsets

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

通过振荡器和射频信号路径的对称布局，可以将LO泄漏降到最低。
LO泄漏主要来自电路和LO波形的随机或确定的不对称性

### 镜像清除和low if 接收机

##### 偏移消除

用C1电容, 偏移消除：高通滤波器
这样的网络也会在零频率附近去除一部分信号的频谱，引入符号间干扰

##### Flicker Noise

An 802.11g receiver exhibits a baseband flicker noise corner frequency of 200 kHz. Determine the flicker noise penalty

 fBW = 10 MHz, fc = 200 kHz, and hence



##### 希尔伯特变换

The shift-by-90 ° operation is also called the “Hilbert transform”.

在+ωc的脉冲被顺时针旋转，在-ωc的脉冲被逆时针旋转。

例题 1 :在相位图中，我们只需将一个相位乘以-j，就可以将其顺时针旋转90°。这与希尔伯特变换不一致吗？

不，它不是。相位是Aexp(jωct)的表示，即只表示正频率内容。也就是说，我们隐含地假定，如果Aexp(jωct)乘以-j，那么Aexp(-jωct)也乘以+j。

例题 2 : 绘制Acos ωct + jA sinωct的频谱。

Asinωct的频谱乘以j，使两个脉冲逆时针旋转90°。将这个频谱与Acos ωct的频谱相加后，我们得到了下图所示的单侧频谱（右图）。当然，这是可以预期的，因为Acos ωct + jA sinωct = Aexp(-jωct)，其傅里叶变换是一个位于ω = +ωc的单一脉冲。

### Hartley Architecture

If we shift I(t) or Q(t) by another 90 ° before adding them, the image may be removed.

另一个关键的缺点来自于R1和C1的绝对值的变化。

如果转换到中频的信号有很宽的带宽，那么RC-CR部分产生的另一个缺点就会表现出来。



低中频结构的另一个变体如下图所示，下变频信号被应用于信道选择滤波器和放大器，如同在直接转换接收器中一样。然后将结果数字化，并在求和之前在数字域中进行希尔伯特变换。 这是对模拟电路而言最简单的方法,采样率不需要特别高. 

 "on-off 键控"（OOK）调制是ASK的一个特例，载波振幅在零和最大之间切换。

当LO被二进制基带数据直接打开和关闭时（上图左），如果LO的波动足够大，PA也会经历相对完整的切换，并向天线提供OOK波形。上图（右）可以避免LO不容易被PLL控制的问题。

### 发送机
