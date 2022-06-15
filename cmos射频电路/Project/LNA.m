clear;
clc;
Tox = 4E-9 *10^6  ;% um from PSpice model of TSMC's 180nm MOSFET process .
E0=8.85E-18;  %  F/um (Jacop Backer : CMOS circuit design ... , pp114)
Er=3.97  ; % , same book
L = 50 ;%  um
un = 670E6 ;% For a NMOS: u0 = 670 cm^2/(V*s)
Cox=E0*Er/Tox; %  Cox=8.784E-15F/um²
Vth= 0.7 ;% V 
W= [0:50:200];
Vgs=[500E-3:100E-3:900E-3];
[W,Vgs]=meshgrid([0:50:200],[500E-3:100E-3:900E-3]);
Id = (1/2)*un*Cox*(W./L)*(Vgs-Vth).^2;
gm2 = sqrt(2*un*Cox*Id.*W/L); 
Rs = 50 ;% 欧姆
Cgs= 80E-15 ;
gamma=1;
Gain =10;
%%
% ppt21 resistive feedback
% gain
Rf = 50:10:1000;
plot(Rf,20*log10(Rf/Rs));
yline(15);
yline(25);
index = find(y ==25); 
disp(y(index))

% noise figure
%NF = 1+ 4*Rs/Rf + gamma +gamma.*gm2.*Rs;
%mesh(W,Vgs,NF);

%% 
% paper
% F = 1+ (1./Rs).*gamma/gm;


% mesh(Vgs,W,F)

%%
% LNA ppt36

% s = j *w 
% Gain = (1/(Cgs *s) + L1*s + gm *L1/(Cgs)) *(1- 2*Cgd/Cgs  - L1*Cgd*s^2 - (R1*Cgd + gm*L1*Cgd/Cgs)*s)

% NF  = 1+ gm*Rs*gamma*(w0/wT)^2
