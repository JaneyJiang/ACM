#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;
#define LEN 6
#define MAX 1000
char mulpty[MAX] = { '\0' };
void mulptyBig(char*a, char*b)
{
	int temp[MAX] = { 0 };
	int i, j, z, num, pind, count;
	bool flag = false;

	pind = -1;
	count = 0;
	for (i = strlen(a) - 1; i >= 0; i--)
	{
		if (a[i] == '.')
			pind += strlen(a) - i - 1;
		else {
			z = count;
			for (j = strlen(b) - 1; j >= 0; j--)
			{
				if (b[j] == '.')
				{
					if (pind == -1)
					{
						pind = 0;
						pind += strlen(b) - j - 1;
					}
				}
				else {
					num = (b[j] - '0')*(a[i] - '0') + temp[z];
					temp[z] = num % 10;
					temp[++z] += num / 10;
				}
			}
			count++;
		}
	}
	if (pind != -1)
		flag = true;
	for (j = 0, i = 0; i <= z; i++)
	{
		if (flag == true && temp[i] == 0)
			continue;
		else if (i == pind)
		{
			mulpty[j++] = '.';
			mulpty[j++] = temp[i] + '0';
			flag = false;
		}
		else
		{
			mulpty[j++] = temp[i] + '0';
			flag = false;
		}

	}
	mulpty[j] = '\0';
	_strrev(mulpty);


}

void printMulpty(char*a)
{
	bool flag = true;
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] == '0' && flag == true)
			continue;
		else
		{
			cout << a[i];
			flag = false;
		}
	}
	cout << endl;
}

void bigfloatpow()
{
	char s[LEN + 1];
	int n;
	while (cin >> s >> n)
	{
		strcpy_s(mulpty, s);
		while (n > 1)
		{
			n--;
			mulptyBig(mulpty, s);
		}
		printMulpty(mulpty);
	}
}

int main(int argc, char* argv[])
{
	bigfloatpow();
	return 0;
}