#include "stdafx.h"
#include "Framework.h"


int main()
{
    FRAMEWORK.Init(1200,720, "Timeber!!");
    FRAMEWORK.Do();
    FRAMEWORK.Release();

    return 0;
}