// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//
// 所有的链表一定有头结点head
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息

// Windows 头文件: 
#include <afxwin.h>
#if defined (CString)
#undef CString
#endif

#include <windows.h>
#include <commctrl.h>
#include <atlbase.h>
#include <atlstr.h>
#include <atlconv.h>


// C 运行时头文件
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO:  在此处引用程序需要的其他头文件
