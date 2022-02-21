//Ex6.7  编写一个函数，当它第一次被调用时返回0，以后每次被调用返回值加1。

int ret()
{
    static int ctr = 0;
    return ctr++;
}