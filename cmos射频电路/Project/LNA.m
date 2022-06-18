clear;
clc;
Tox = 4E-9 *10^6  ;% um from PSpice model of TSMC's 180nm MOSFET process .
E0=8.85E-18;  %  F/um (Jacop Backer : CMOS circuit design ... , pp114)
Er=3.97  ; % , same book
L = 0.18 ;%  um
un = 670E8 ;% For a NMOS: u0 = 670 cm^2/(V*s)
Cox=E0*Er/Tox; %  Cox=8.784E-15F/um²
Vth= 0.7 ;% V 
[W,Vgs]=meshgrid([0.36:0.09:3.6],[0.7:0.05:3.3]);
%W = 3.6
k = un.*Cox.*W./L; % k =0.5E-3
%Vgs = 2.4

Id = (1/2).*k.*(Vgs-Vth).^2;
Rs = 50 ;% 
Cgs= 80E-15 ;
gamma=2/3;


%% M2

% Id = (1/2).*k.*(Vgs-Vth).^2;
mesh(W,Vgs,Id);
title('Id versus Vgs2 & W2');  
x1=xlabel('Vgs2 / V');      
x2=ylabel('W2 / um');       
x3=zlabel('Id/A');        
set(x1,'Rotation',30);   
set(x2,'Rotation',-30);  
hold on
z=0.017.*(W>=0.36&W<=3.6);
surf(W,Vgs,z);
figure();
[C, h] =contour(W,Vgs,Id);
clabel(C, h);
xlabel('W /um ');ylabel('Vgs / V') 
title('Id versus Vgs2 & W2 （Contour lines）');

figure();

%% gain
Rf = 50:10:1000;
plot(Rf,20*log10(Rf/Rs));
yline(15);
yline(25);
xlabel('Rf/Ω');ylabel('Gain/dB') 
title('Gain versus Rf');
%% gm 
gm1 = sqrt(2*un*Cox*Id.*W/L); 
mesh(W,Vgs,gm1);
title('gm1 versus Vgs & W');  
x1=xlabel('Vgs / V');      
x2=ylabel('W / um');       
x3=zlabel('gm1/ S');        
set(x1,'Rotation',30);   
set(x2,'Rotation',-30);  
hold on
z=0.02.*(W>=0.36&W<=3.6);
surf(W,Vgs,z);
figure();
[C, h] =contour(W,Vgs,gm1);
clabel(C, h);
xlabel('W /um ');ylabel('Vgs / V') 
title('gm1 versus Vgs & W （Contour lines）');

%% bandwidth
fT = (Vgs-Vth).*0.75.*un./(pi*L^2);
 plot(Vgs,fT./10E9);
title('fT versus Vgs');  
xlabel('Vgs / V');ylabel('fT/GHz') 


%% noise figure
Rf = 500;
gm2 = sqrt(2*un*Cox*Id.*W/L);
NF = 1+ 4*Rs/Rf + gamma +gamma.*gm2.*Rs;
mesh(W,Vgs,NF);
title('Noise Figure versus Vgs2 & W');
x1=xlabel('Vgs2 / V');
x2=ylabel('W2 / um');
x3=zlabel('Noise Figure NF [dB]');
set(x1,'Rotation',30);
set(x2,'Rotation',-30);

figure();
[C, h] =contour(W,Vgs,NF);
clabel(C, h);
title('NF versus Vgs2 & W2 （Contour lines）');
xlabel('W2 /um ');ylabel('Vgs2 / V') 



