clear;
clc;
Tox = 4E-9 *10^6  ;% um from PSpice model of TSMC's 180nm MOSFET process .
E0=8.85E-18;  %  F/um (Jacop Backer : CMOS circuit design ... , pp114)
Er=3.97  ; % , same book
L = 50 ;%  um
un = 670E8 ;% For a NMOS: u0 = 670 cm^2/(V*s)
Cox=E0*Er/Tox; %  Cox=8.784E-15F/um²
Vth= 0.7 ;% V 
[W,Vgs]=meshgrid([0:50:600],[3:0.5:9]);
k = un.*Cox.*W./L; % k =0.5E-3
Id = (1/2).*k.*(Vgs-Vth).^2;
Rs = 50 ;% 欧姆
Cgs= 80E-15 ;
gamma=1;

%% gain
% ppt21 resistive feedback

% Rf = 50:10:1000;
% plot(Rf,20*log10(Rf/Rs));
% yline(15);
% yline(25);
% xlabel('Rf/Ω');ylabel('Gain/dB') 

%% gm 
% gm1 = sqrt(2*un*Cox*Id.*W/L); 
% mesh(W,Vgs,gm1);
% title('gm1 versus Vgs & W');  
% x1=xlabel('Vgs / V');      
% x2=ylabel('W / um');       
% x3=zlabel('gm1/ S');        
% set(x1,'Rotation',30);   
% set(x2,'Rotation',-30);    
% figure();
% title('gm1 versus Vgs & W （Contour lines）');
% [C, h] =contour(W,Vgs,gm1);
% clabel(C, h);
% xlabel('W /um ');ylabel('Vgs / V') 

%%
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
