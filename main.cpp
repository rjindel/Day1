// Type your code here, or load an example.
#include <stdio.h>

int main()
{
	FILE * captchaFile = nullptr;
	fopen_s(&captchaFile, "captcha.txt", "r");
	const int MAX_LENGTH = 2560;
	char captcha[MAX_LENGTH];
	size_t bytesRead = fread(captcha, sizeof(char), MAX_LENGTH, captchaFile);

	//auto captcha = "112283488";
	int checksum = 0;
	//constexpr int length = sizeof(captcha);
	captcha[bytesRead] = 0;
	printf("Length of \'%s\' is %i\n", captcha, bytesRead);
	for (size_t i = 0; i < bytesRead; i++)
	{
		//if (captcha[i] == captcha[(i + 1) % bytesRead])
		if (captcha[i] == captcha[(i + bytesRead/2) % bytesRead])
		{
			checksum += captcha[i] - '0';
		}

	}

	printf("Checksum is %i\n", checksum);

	fclose(captchaFile);
	return checksum;
}