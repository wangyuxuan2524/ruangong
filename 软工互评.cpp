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
	printf("��������ݣ�");
	scanf("%d",&year);
	printf("�������·ݣ�");
	scanf("%d",&month);
	printf("�������գ�");
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
	printf("\t  \t  \t%d��%d��\n",year,month);
	printf("\tһ\t��t\t��\t��\t��\t��\t��\n");
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
		printf("1956��10��8���ҹ���һ����������о����������������о�Ժ������");
	else if(year==1970&&month==4&&dayth==24)
	printf("\n1970��4��24�ճ���һ�����ػ���ھ�Ȫ���Ƿ������ĳɹ��ط����˶�����һ�����ǣ�\n�ҹ���Ϊ������������������뷢�����ǵĹ��ҡ�");
	else if(year==1975&&month==11&&dayth==26)
		printf("\n1975��11��26���й������˵�һ�ŷ���ʽң�����ǣ����ǰ�Ԥ���ƻ��ڵ��·��ص��档�й���Ϊ�����ϼ�����������֮������������������Ƿ��ؼ����Ĺ��ҡ�");
	else if(year==1980&&month==5&&dayth==18)
		printf("\n1980��5��18���й���̫ƽ��Ԥ������ɹ��ط�����Զ�����ػ������־���й��߱��˷���߹���������ǵķ���������");
	else if(year==1981&&month==9&&dayth==20)
		printf("\n1981��9��20���й���һö���ػ�����������ſ�ѧʵ�����ǣ������й���һ��һ�����Ƿ��䣬���й���Ϊ�����ϵ���������һ�����Ƿ��似���Ĺ��ҡ�");
	else printf("\n\t����û��ʲô��?ף�����쿪��?~~\n");
}




