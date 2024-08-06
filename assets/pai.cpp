#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
int main(){
	struct timeval s1,s,e; //这个函数的格式就是这样
	int t1,t2;
	for(int i=1;i<=10000;++i){
		system("shujv.exe");//重定向输出
		gettimeofday(&s1,NULL);
		system("1.exe"); //重定向输入输出
		gettimeofday(&s,NULL);
		system("2.exe");//重定向输入输出
		gettimeofday(&e,NULL);
		t1=(s.tv_sec-s1.tv_sec)*1000+(s.tv_usec-s1.tv_usec)/1000; //把时间转化成毫秒
		t2=(e.tv_sec-s.tv_sec)*1000+(e.tv_usec-s.tv_usec)/1000; //把时间转化成毫秒
		if(system("fc 1.out 2.out")){
			puts("WA");
			return 0;
		}
		else printf("AC,test point #%d,btime %dms ,baotime %dms\n",i,t1,t2);
                                   //分别输出数据的组数，第一个程序的运行时间，第二个程序的运行时间。
	}
}