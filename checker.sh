make fclean
cd ..
cp -rf ft_printf PRINTFTEST
cp PRINTFTEST/Makefile PRINTFTEST/ft_printf
cp PRINTFTEST/printf.h PRINTFTEST/ft_printf/includes/printf.h
rm PRINTFTEST/ft_printf/srcs/main.c
rm PRINTFTEST/ft_printf/srcs/main2.c
rm PRINTFTEST/ft_printf/srcs/main3.c
rm PRINTFTEST/ft_printf/srcs/main4.c
rm PRINTFTEST/ft_printf/srcs/main5.c
cd checker
sh 42FileChecker.sh
