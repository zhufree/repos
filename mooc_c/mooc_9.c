#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *start = "$GPRMC";
const char *end = "END";
const char *A = ",A,";
char hourStr[8];

int toTen(char *n) {
	int result = 0;
	switch((int)n[0]) {
		case (int)'A':
			result += 10*16;
			break;
		case (int)'B':
			result += 11*16;
			break;
		case (int)'C':
			result += 12*16;
			break;
		case (int)'D':
			result += 13*16;
			break;
		case (int)'E':
			result += 14*16;
			break;
		case (int)'F':
			result += 15*16;
			break;
		default:
			result += (n[0]-48)*16;
	}
	switch((int)n[1]) {
		case (int)'A':
			result += 10;
			break;
		case (int)'B':
			result += 11;
			break;
		case (int)'C':
			result += 12;
			break;
		case (int)'D':
			result += 13;
			break;
		case (int)'E':
			result += 14;
			break;
		case (int)'F':
			result += 15;
			break;
		default:
			result += (n[1]-48);
	}
	return result;
}
int check(char *line) {
	int idx = 0;
	int checkNum = 0;
	while(line[++idx]!='*') {
		checkNum = checkNum^line[idx];
	}
	int result = checkNum%65536;
	char *star;
	star = &line[idx+1];
	if (result == toTen(star) && strstr(line, A)) {
		return 1;
	} else {
		return 0;
	}
};

char *calcTime(char *line){
	char *time = &line[7];
	
	int hour = (time[0]-48)*10+(time[1]-48);
	if (hour >= 0 && hour < 2) {
		hourStr[0] = '0';
		hourStr[1] = (char)(hour+8+48);
	} else if (hour >= 2 && hour <11) {
		hourStr[0] = '1';
		hourStr[1] = (char)(hour+8-10+48);
	} else if (hour>=12 && hour < 16){
		hourStr[0] = '2';
		hourStr[1] = (char)(hour+8-20+48);
	} else {
		hourStr[0] = '0';
		hourStr[1] = (char)(hour+8-24+48);
	}
	for (int i = 2, j = 2; i < 6, j < 8; ++i, ++j)
	{
		if (j == 2 || j == 5) {
			hourStr[j++] = ':';
		}
		hourStr[j] = time[i];
		// printf("j=%d, i=%d, hourStr[j]=%c, time[i]=%c\n", j, i, hourStr[j], time[i]);
		
	}
	// char *hourPoint = &hourStr[2];
	// time = &line[9];
	// while(*time!='.') {
	// 	*hourPoint++ = *time++;
	// }
	// printf("%s\n", hourStr);
	return hourStr;
};
int main(int argc, char const *argv[])
{
	/* 
	NMEA-0183协议是为了在不同的GPS（全球定位系统）导航设备中建立统一的BTCM（海事无线电技术委员会）标准
	由美国国家海洋电子协会（NMEA-The National Marine Electronics Associa-tion）制定的一套通讯协议
	GPS接收机根据NMEA-0183协议的标准规范，将位置、速度等信息通过串口传送到PC机、PDA等设备。
	NMEA-0183协议是GPS接收机应当遵守的标准协议，也是目前GPS接收机上使用最广泛的协议，
	大多数常见的GPS接收机、GPS数据处理软件、导航软件都遵守或者至少兼容这个协议。
	NMEA-0183协议定义的语句非常多，但是常用的或者说兼容性最广的语句只有
	$GPGGA、$GPGSA、$GPGSV、$GPRMC、$GPVTG、$GPGLL等。

	其中$GPRMC语句的格式如下：
    $GPRMC,024813.640,A,3158.4608,N,11848.3737,E,10.05,324.27,150706,,,A*50
	这里整条语句是一个文本行，行中以逗号“,”隔开各个字段，每个字段的大小（长度）不一，
	这里的示例只是一种可能，并不能认为字段的大小就如上述例句一样。

	字段0：$GPRMC，语句ID，表明该语句为Recommended Minimum Specific GPS/TRANSIT Data（RMC）推荐最小定位信息
	字段1：UTC时间，hhmmss.sss格式
	字段2：状态，A=定位，V=未定位
	字段3：纬度ddmm.mmmm，度分格式（前导位数不足则补0）
	字段4：纬度N（北纬）或S（南纬）
	字段5：经度dddmm.mmmm，度分格式（前导位数不足则补0）
	字段6：经度E（东经）或W（西经）
	字段7：速度，节，Knots
	字段8：方位角，度
	字段9：UTC日期，DDMMYY格式
	字段10：磁偏角，（000 - 180）度（前导位数不足则补0）
	字段11：磁偏角方向，E=东W=西
	字段16：校验值
	这里，“*”为校验和识别符，其后面的两位数为校验和，
	代表了“$”和“*”之间所有字符（不包括这两个字符）的异或值的十六进制值。
	上面这条例句的校验和是十六进制的50，也就是十进制的80。
	提示：^运算符的作用是异或。将$和*之间所有的字符做^运算(第一个字符和第二个字符异或，结果再和第三个字符异或，依此类推)
	之后的值对65536取余后的结果，
	应该和*后面的两个十六进制数字的值相等，否则的话说明这条语句在传输中发生了错误。
	注意这个十六进制值中是会出现A-F的大写字母的。

	现在，你的程序要读入一系列GPS输出，其中包含$GPRMC，也包含其他语句。在数据的最后，有一行单独的
    	END
	表示数据的结束。

	你的程序要从中找出$GPRMC语句，计算校验和，找出其中校验正确，并且字段2表示已定位的语句，从中计算出时间，换算成北京时间。
	一次数据中会包含多条$GPRMC语句，以最后一条语句得到的北京时间作为结果输出。
	你的程序一定会读到一条有效的$GPRMC语句。

	输出格式：
	6位数时间，表达为：
	hh:mm:ss
	其中，hh是两位数的小时，不足两位时前面补0；mm是两位数的分钟，不足两位时前面补0；ss是两位数的秒，不足两位时前面补0。
	*/
	freopen("in.txt", "r", stdin);
	char line[200];
	char *resultTime;
	while(scanf("%s", line)!=EOF) {
		if (strcmp(line, end)!=0 && strncmp(line, start, 6) == 0) {
			if (check(line)) {
				// printf("check pass\n");
				resultTime = calcTime(line);
			}
		}
	}
	printf("%s\n", resultTime);
	return 0;
}