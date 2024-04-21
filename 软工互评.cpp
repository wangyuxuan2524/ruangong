#include<stdio.h>
#include<stdlib.h>
int month_n[13]={0};
int year_n[101]={0};//1930-2030 1-100
int n=0;
int main()
{
	int leapornot(int year);
	void nn(int year,int month);
	int weekth(int year,int month);
	void print(int year,int month,int weekth,int dayth);

	int year,month,day;
	printf("请输入年份：");
	scanf("%d",&year);
	printf("请输入月份：");
	scanf("%d",&month);
	printf("请输入日：");
	scanf("%d",&day);
	int leap=leapornot(year);
	
	int week=weekth(year,month);
	print(year,month,week,day);

	system("pause");
}
int leapornot(int year)
{
	if((year%4==0&&year%100!=0)||year%400==0)
	return 1;
	else return 0;
}
void nn(int year,int month)
{
	int leapornot(int year);
	int leap=leapornot(year);
	
	if(leap)*(month_n+2)=29;
	else *(month_n+2)=28;
	*(month_n+1)=31;
	*(month_n+3)=31;
	*(month_n+5)=31;
	*(month_n+7)=31;
	*(month_n+8)=31;
	*(month_n+10)=31;
	*(month_n+12)=31;
	*(month_n+4)=30;
	*(month_n+6)=30;
	*(month_n+9)=30;
	*(month_n+11)=30;

	return;
}
int weekth(int year,int month)
{
	void nn(int year,int month);
	if(year==2018)
	{
		nn(year,month);
		for(int f=1;f<month;f++)
		{
			n+=*(month_n+f);
		}
		return (n%7);
	}
	if(year<2018)
	{
		nn(year,month);
		int t=year;
		for(t=t+1;t<2018;t++)
		{
			int yearn=0;
			if(leapornot(t))yearn=366;
			else yearn=365;
			n+=yearn;
		}
		for(int f=12;f>=month;f--)
		{
			n+=*(month_n+f);
		}
		return(7-n%7);
	}
	if (year>2018)
	{
		nn(year,month);
		int sum=0;
		int t=year;
		for(t=t-1;t>=2018;t--)
		{
			
			int yearn=0;
			if(leapornot(t))yearn=366;
			else yearn=365;
			n+=yearn;
		}
		
		for(int f=1;f<month;f++)
		{
			n+=*(month_n+f);
		}
		return (n%7);
	}
}
void print(int year,int month,int weekth,int dayth)
{
	void nn(int year,int month);
	printf("\t  \t  \t%d年%d月\n",year,month);
	printf("\t一\t二t\t三\t四\t五\t六\t日\n");
	for(int j=0;j<weekth;j++)
	{printf("\t ");}  
	int x=weekth;
	nn(year,month);
	for(int k=1;k<=*(month_n+month);k++)
	{
		printf("\t%d",k);
		x++;
		if(x%7==0)printf("\n");
	}
	if(year==1956&&month==10&&dayth==8)
		printf("1956年10月8日我国第一个火箭导弹研究机构国防部第五研究院成立。");
	else if(year==1970&&month==4&&dayth==24)
	printf("\n1970年4月24日长征一号运载火箭在酒泉卫星发射中心成功地发射了东方红一号卫星，\n我国成为世界第三个独立研制与发射卫星的国家。");
	else if(year==1975&&month==11&&dayth==26)
		printf("\n1975年11月26日中国发射了第一颗返回式遥感卫星，卫星按预定计划于当月返回地面。中国成为世界上继美国和苏联之后第三个掌握人造卫星返回技术的国家。");
	else if(year==1980&&month==5&&dayth==18)
		printf("\n1980年5月18日中国向太平洋预定海域成功地发射了远程运载火箭，标志着中国具备了发射高轨道人造卫星的发射能力。");
	else if(year==1981&&month==9&&dayth==20)
		printf("\n1981年9月20日中国用一枚运载火箭发射了三颗科学实验卫星，这是中国第一次一箭多星发射，是中国成为世界上第三个掌握一箭多星发射技术的国家。");
	else printf("\n\t今天没有什么了?祝您天天开心?~~\n");
}




