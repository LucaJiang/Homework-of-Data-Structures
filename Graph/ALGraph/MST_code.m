%MSP_TSP_粤港澳大湾区
%求城市距离
%%init
clc,clear
num_city=11;
scale_re=20;%20km
pic=imread('大湾区地图.PNG');

%%scale
imshow(pic,'InitialMagnification',80);
text(10,10,'1.点击比例尺的左端和右端','Color','r','FontSize',10)
scale_input=ginput(2)
scale=norm(scale_input(1,:)-scale_input(2,:),2)
ratio=scale_re/scale
%dis_re=dis*ratio

%%city distance
text(10,50,'2.依次点击城市:香港 澳门 广州 深圳 珠海 佛山 惠州 东莞 中山 江门 肇庆','Color','b','FontSize',10)
city_pos=ginput(num_city)
%text(10,90,'3.点击完成，enter键退出','Color','g','FontSize',10)
close
city_dis=zeros(11);
for i=1:num_city
    for j=i:num_city
        city_dis(i,j)=norm(city_pos(i,:)-city_pos(j,:),2);
    end
end
disp('11城市距离(KM)')
disp('香港 澳门 广州 深圳 珠海 佛山 惠州 东莞 中山 江门 肇庆')
city_realdis=city_dis.*ratio
city_realdis_int=round(city_realdis);

%MST
%init graph
name={'香港','澳门','广州 ','深圳','珠海','佛山','惠州','东莞','中山','江门','肇庆'}';
g=graph(city_realdis,name,'upper'); %上三角

%mst prim
gp1=plot(g,'NodeColor','y');
title('MST-Prim')
%tree,predecessor nodes
[t1,pred1]=minspantree(g,'Method','dense');%稠密图prim
highlight(gp1,t1)

%mst kruskal
gp2=plot(g,'NodeColor','y');
title('MST-Kruskal')
[t2,pred2]=minspantree(g,'Method','sparse');%稀疏图kruskal
highlight(gp2,t2)
hold off

