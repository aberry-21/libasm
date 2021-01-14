make bonus
mv libasm.a src_for_testing
cd src_for_testing
gcc main.c list_utils.c ft_list_size_test.c ft_list_push_front_test.c test_strcmp.c test_strdup.c test_write.c test_read.c test_strcpy.c test_strlen.c testlibasm.h libasm.a && ./a.out
rm -rf a.out
rm -rf testlibasm.h.gch
mv libasm.a ../
cd ..
make fclean