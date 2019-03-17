/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:23:26 by artprevo          #+#    #+#             */
/*   Updated: 2019/02/28 19:10:02 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		main(int ac, char **av)
{
	av = 0;
	ac = 1;
	printf("-------------------------------\n");
	printf("EASY\n");
	printf("-------------------------------\n");
	printf("\n");
	printf("\n");
	printf("test\n");
	printf("test\n");
	printf("1234\n");

	printf("-------------------------------\n");
	printf("LE POURCENTAGE\n");
	printf("-------------------------------\n");
	printf("%%\n");
	printf("%5%\n");
	printf("%-5%\n");
	printf("%05%\n");
	printf("%-05%\n");
	printf("% h%\n");
	printf("%.0%\n");

	printf("-------------------------------\n");
	printf("x ET X\n");
	printf("-------------------------------\n");
	printf("%x\n", 42);
	printf("%X\n", 42);
	printf("%x\n", 0);
	printf("%X\n", 0);
	printf("%x\n", -42);
	printf("%X\n", -42);
	printf("%lx\n", 4294967296);
	printf("%lX\n", 4294967296);
	printf("-------------------------------\n");

	printf("%10x\n", 42);
	printf("%-10x\n", 42);

	printf("-------------------------------\n");
	printf("%lx\n", 4294967296);
	printf("%lX\n", 4294967296);

	printf("-------------------------------\n");
	printf("%lx\n", 4294967296);
	printf("%lX\n", 4294967296);

	printf("-------------------------------\n");
	printf("%lx\n", 4294967295);
	printf("%lx\n", 4294967296);

	printf("-------------------------------\n");
	printf("%lx\n", -4294967296);
	printf("%lx\n", -4294967297);

	printf("-------------------------------\n");
	printf("%lx\n", 9223372036854775807);

	printf("-------------------------------\n");
	printf("%010x\n", 542);
	printf("%-15x\n", 542);
	printf("%2x\n", 542);
	printf("%.2x\n", 5427);
	printf("%5.2x\n", 5427);

	printf("-------------------------------\n");
	printf("%#x\n", 42);
	printf("%lx\n", 9223372036854775807);
	printf("%#lx\n", 9223372036854775807);

	printf("-------------------------------\n");
	printf("%#x\n", 0);
	printf("%#x\n", 42);
	printf("%#X\n", 42);
	printf("%#8x\n", 42);
	printf("%#08x\n", 42);
	printf("%#-8x\n", 42);

	printf("-------------------------------\n");
	printf("@moulitest: %#.x %#.0x\n", 0, 0);
	printf("@moulitest: %.x %.0x\n", 0, 0);
	printf("@moulitest: %5.x %5.0x\n", 0, 0);

	printf("-------------------------------\n");
	printf("STRING\n");
	printf("-------------------------------\n");
	printf("%s\n", "abc");
	printf("%s\n", "this is a string");
	printf("%s \n", "this is a string");
	printf("%s  \n", "this is a string");
	printf("this is a %s\n", "string");
	printf("%s is a string\n", "this");
	printf("Line Feed %s\n", "\n");

	printf("%10s is a string\n", "this");
	printf("%10s is a string\n", "this");
	printf("%.2s is a string\n", "this");
	printf("%5.2s is a string\n", "this");
	printf("%10s is a string\n", "this");
	printf("%.2s is a string\n", "this");
	printf("%5.2s is a string\n", "this");

	printf("%-10s is a string\n", "this");
	printf("%-10s is a string\n", "this");
	printf("%-.2s is a string\n", "this");
	printf("%-5.2s is a string\n", "this");
	printf("%-10s is a string\n","this");
	printf("%-.2s is a string\n", "this");
	printf("%-5.2s is a string\n", "this");

	printf("%s %s\n", "this", "is");
	printf("%s %s %s\n", "this", "is", "a");
	printf("%s %s %s %s\n", "this", "is", "a", "multi");
	printf("%s %s %s %s string. gg!\n", "this", "is", "a", "multi");
	printf("%s%s%s%s%s\n", "this", "is", "a", "multi", "string");

	printf("@moulitest: %s\n", NULL);
	printf("%c\n", 0);
	printf("%s %s\n", NULL, "string");

	printf("-------------------------------\n");
	printf("CHAR\n");
	printf("-------------------------------\n");
	printf("%c\n", 42);
	printf("%5c\n", 42);
	printf("%5c\n", 42);
	printf("%-5c\n", 42);
	printf("@moulitest: %c\n", 0);
	printf("%2c\n", 0);
	printf("null %c and text\n", 0);
	printf("%c\n", 0);

	printf("-------------------------------\n");
	printf("OCTAL\n");
	printf("-------------------------------\n");
	printf("%o\n", 40);
	printf("%5o\n", 41);
	printf("%05o\n", 42);
	printf("%-5o\n", 2500);
	printf("%#6o\n", 2500);
	printf("%-#6o\n", 2500);
	printf("%-5o\n", 2500);
	printf("%-5.10o\n", 2500);
	printf("%-10.5o\n", 2500);
	printf("@moulitest: %o\n", 0);
	printf("@moulitest: %.o %.0o\n", 0, 0);
	printf("@moulitest: %5.o %5.0o\n", 0, 0);
	printf("@moulitest: %#.o %#.0o\n", 0, 0);
	printf("@moulitest: %.10o\n", 42);

	printf("-------------------------------\n");
	printf("INT\n");
	printf("-------------------------------\n");

	printf("%d\n", 1);
	printf("the %d\n", 1);
	printf("%d is one\n", 1);
	printf("%d\n", -1);
	printf("%d\n", 4242);
	printf("%d\n", -4242);
	printf("%d\n", 2147483647);
	printf("%ld\n", 2147483648);
	printf("%ld\n", -2147483648);
	printf("%ld\n", -2147483649);

	printf("%d\n", 42);
	printf("%d\n", -42);
	printf("%d\n", 42);
	printf("%d\n", -42);
	printf("%d\n", 42);
	printf("%d\n", -42);

	printf("%d\n", 42);
	printf("%d\n", -42);
	printf("%d\n", 0);
	printf("%d\n", 42);
	printf("%d\n", -42);
	printf("%d\n", 42);
	printf("%d\n", -42);
	printf("%d\n", 42);
	printf("%d\n", -42);
	printf("%d\n", 42);
	printf("%d\n", -42);
	printf("%d\n", 42);
	printf("%d\n", -42);
	printf("%d\n", 42);
	printf("%d\n", -42);

	printf("%d\n", -42);
	printf("%d\n", -42);

	printf("%5d\n", 42);
	printf("%5d\n", 42);
	printf("%05d\n", 42);
	printf("%0+5d\n", 42);
	printf("%5d\n", -42);
	printf("%5d\n", -42);
	printf("%05d\n", -42);
	printf("%0+5d\n", -42);

	printf("%-5d\n", 42);
	printf("%-5d\n", 42);
	printf("%-5d\n", 42);
	printf("%-5d\n", 42);
	printf("%-5d\n", -42);
	printf("%-5d\n", -42);
	printf("%-5d\n", -42);
	printf("%-5d\n", -42);

	printf("-------------------------------\n");
	printf("INT SHORT\n");
	printf("-------------------------------\n");
	printf("%d\n", 32767);
	printf("%d\n", 32768);

	printf("-------------------------------\n");
	printf("SIGNED CHAR\n");
	printf("-------------------------------\n");
	printf("%d\n", 127);
	printf("%d\n", 128);
	printf("%d\n", -128);
	printf("%d\n", -129);

	printf("-------------------------------\n");
	printf("INT LONG\n");
	printf("-------------------------------\n");
	printf("%d\n", 2147483647);
	printf("%ld\n", -2147483648);
	printf("%ld\n", 2147483648);
	printf("%ld\n", -2147483649);

	printf("-------------------------------\n");
	printf("INT LONG LONG\n");
	printf("-------------------------------\n");
	printf("%ld\n", 9223372036854775807);

	printf("-------------------------------\n");
	printf("INTMAXXX\n");
	printf("-------------------------------\n");
	printf("%ld\n", 9223372036854775807);

	printf("-------------------------------\n");
	printf("INT LE RETOUR\n");
	printf("-------------------------------\n");
	printf("%ld\n", 4294967295);
	printf("%ld\n", 4294967296);
	printf("%d\n", -0);
	printf("%d\n", -1);

	printf("%d\n", 1);
	printf("%d %d\n", 1, -2);
	printf("%d %d %d\n", 1, -2, 33);
	printf("%d %d %d %d\n", 1, -2, 33, 42);
	printf("%d %d %d %d gg!\n", 1, -2, 33, 42);

	printf("-------------------------------\n");
	printf("PRECISION\n");
	printf("-------------------------------\n");
	printf("%4.15d\n", 42);
	printf("%.2d\n", 4242);
	printf("%.10d\n", 4242);
	printf("%10.5d\n", 4242);
	printf("%-10.5d\n", 4242);
	printf("% 10.5d\n", 4242);
	printf("%+10.5d\n", 4242);
	printf("%-+10.5d\n", 4242);
	printf("%03.2d\n", 0);
	printf("%03.2d\n", 1);
	printf("%03.2d\n", -1);
	printf("@moulitest: %.10d\n", -42);
	printf("@moulitest: %.d %.0d\n", 42, 43);
	printf("@moulitest: %.d %.0d\n", 0, 0);
	printf("@moulitest: %5.d %5.0d\n", 0, 0);

	printf("-------------------------------\n");
	printf("UNSIGNED\n");
	printf("-------------------------------\n");
	printf("%u\n", 0);
	printf("%u\n", 1);
	printf("%u\n", -1);
	printf("%ld\n", 4294967295);
	printf("%ld\n", 4294967296);

	printf("%5ld\n", 4294967295);
	printf("%15ld\n", 4294967295);
	printf("%-15ld\n", 4294967295);
	printf("%015ld\n", 4294967295);
	printf("%ld\n", 4294967295);
	printf("%ld\n", 4294967295);

	printf("%ld\n", 4294967295);
	printf("%ld\n", 4294967296);
	printf("%d\n", -42);

	printf("%ld\n", 4999999999);

	printf("%ld\n", 4999999999);

	printf("%ld\n", 4294967296);

	printf("@moulitest: %.5u\n", 42);

	printf("-------------------------------\n");
}
