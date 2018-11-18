#include <stdio.h>
#include <stdlib.h>

typedef struct Complex {
	int real;
	int imag;
	void (*read_ptr)(struct Complex *);
	void (*display_ptr)(struct Complex *);
} Complex;

void read_complex(Complex * complex_num)
{
	scanf("%d", &(complex_num -> real));
	scanf("%d", &(complex_num -> imag));
}

void display_complex(Complex * complex_num)
{
	printf("%d ", complex_num -> real);

	if (complex_num -> imag < 0)
		printf("- %di\n", abs(complex_num -> imag));
	else
		printf("+ %di\n", complex_num -> imag);
}

Complex * constructor()
{
	Complex * new_num = (Complex *) malloc(sizeof(Complex));
	new_num -> read_ptr = read_complex;
	new_num -> display_ptr = display_complex;
	return new_num;
}

Complex * multiply_two_complex_nums(Complex * num1, Complex * num2)
{
	Complex * result = constructor();

	result -> real = num1 -> real * num2 -> real - num1 -> imag * num2 -> imag;
	result -> imag = num1 -> real * num2 -> imag + num1 -> imag * num2 -> real;

	return result;
}

Complex * multipy_complex_nums(int n, Complex * nums[])
{
	for (int i = 0; i < n - 1; i++)
		nums[i + 1] = multiply_two_complex_nums(nums[i], nums[i + 1]);
	return nums[n - 1];
}

int main()
{
	Complex * num = constructor();
	num -> read_ptr(num);
	num -> display_ptr(num);
	return 0;
}
