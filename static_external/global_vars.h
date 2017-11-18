#ifndef GLOBAL_VARS_HPP
#define GLOBAL_VARS_HPP
extern const int global_c;
static int s1 = 0;
void increment_s1();

static void test(); //name test can be often used in different files
void pretest();

class my_class
{
    private:
        static int global_class_var;
    public:
        static void change_static_var();//static method can be called without method
        static int get_var();
        static void define_var();
};
#endif // GLOBAL_VARS_HPP
