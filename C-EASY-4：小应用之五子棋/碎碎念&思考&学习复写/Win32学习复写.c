
#include <stdio.h>
#include <windows.h>

HANDLE g_hOutput_1=0,g_hOutput_2=0,g_hOutput_3=0,g_hOutput_4=0,g_hOutput_5=0;
LRESULT CALLBACK MyWndProc(HWND hWnd,UINT msgID,WPARAM wParam,LPARAM lParam);

void ONCREATE(HWND hWnd,LPARAM lParam)
{
    CREATESTRUCT* pcs=(CREATESTRUCT*)lParam;
    char *pszText=(char*)pcs->lpCreateParams;
    MessageBox(NULL,pszText,"Information",MB_OK);
    CreateWindowEx(0,"EDIT","Information",WS_CHILD|WS_VISIBLE,0,0,200,200,hWnd,NULL,NULL,NULL);
}//验证WM_CREATE

void OnSize(HWND hWnd,LPARAM lParam)
{
    short nWidth=LOWORD(lParam);
    short nHight=HIWORD(lParam);
    char szText[256]={0};
    sprintf(szText,"WM_SIZE:宽：%d,高：%d\n",nWidth,nHight);
    //MessageBox(hWnd,szText,"Information",MB_OK);
    //WriteConsoleW(g_hOutput,szText,strlen(szText),NULL,NULL);
}

void OnPaint(HWND hWnd)
{
    const char *pszText="WM_PAINT\n";
    WriteConsole(g_hOutput_1,pszText,strlen(pszText),NULL,NULL);
    /*PAINTSTRUCT ps={0};
    HDC hdc=BeginPaint(hWnd,&ps);
    TextOut(hdc,100,100,"Hello",5);
    EndPaint(hWnd,&ps);*/
}

void OnKeyUp(HWND hWnd,WPARAM wParam)
{
    char szText[256]={0};
    sprintf(szText,"WM_KEYUP:键码值=%d\n",wParam);
    WriteConsole(g_hOutput_2,szText,strlen(szText),NULL,NULL);
}

void OnKeyDown(HWND hWnd,WPARAM wParam)
{
    char szText[256]={0};
    sprintf(szText,"WM_KEYDown:键码值=%d\n",wParam);
    WriteConsole(g_hOutput_3,szText,strlen(szText),NULL,NULL);
}

void OnChar(HWND hWnd,WPARAM wParam)
{
    char szText[256]={0};
    sprintf(szText,"WM_CHAR:wParam=%d\n",wParam);
    WriteConsole(g_hOutput_4,szText,strlen(szText),NULL,NULL);
}
void OnLButtonDown(HWND hWnd,WPARAM wParam,LPARAM lParam)
{
    char szText[256]={0};
    sprintf(szText,"WM_LButtonDown:x=%d y=%d\n",LOWORD(lParam),HIWORD(lParam));
    WriteConsole(g_hOutput_4,szText,strlen(szText),NULL,NULL);
}
void OnMouseMove(HWND hWnd,WPARAM wParam,LPARAM lParam)
{
    char szText[256]={0};
    sprintf(szText,"WM_MOUSEMOVE:x=%d y=%d\n",LOWORD(lParam),HIWORD(lParam));
    WriteConsole(g_hOutput_4,szText,strlen(szText),NULL,NULL);
}
void OnMouseWheel(HWND hWnd,WPARAM wParam,LPARAM lParam)
{
    short nDelta=HIWORD(wParam);
    char szText[256]={0};
    sprintf(szText,"WM_MOUSEWHEEL:x=%d y=%d 偏移量：%d\n",LOWORD(lParam),HIWORD(lParam),nDelta);
    WriteConsole(g_hOutput_4,szText,strlen(szText),NULL,NULL);
}
void OnTimer(HWND hWnd,WPARAM wParam)
{
    switch(wParam)
    {
        case 1:
        {
            char szText_1[256]={0};
            sprintf(szText_1,"WM_TIMER:ID=%d\n",wParam);
            WriteConsole(g_hOutput_5,szText_1,strlen(szText_1),NULL,NULL);
            break;
        }
        
        case 2:
        {
            char szText_2[256]={0};
            sprintf(szText_2,"WM_TIMER:ID=%d\n",wParam);
            WriteConsole(g_hOutput_5,szText_2,strlen(szText_2),NULL,NULL);
            break;
        }
    }
    
}
int WINAPI WinMain(HINSTANCE hIns,HINSTANCE hPreIns,LPSTR lpCmdLine,int nCmdShow)
{
    AllocConsole();
    g_hOutput_1=g_hOutput_2=g_hOutput_3=g_hOutput_4=g_hOutput_5=GetStdHandle(STD_OUTPUT_HANDLE);
    WNDCLASS  wc={0};
    wc.cbClsExtra=0;//缓冲区
    wc.cbWndExtra=0;//缓冲区
    wc.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);//背景色
    wc.hCursor=NULL;//鼠标的句柄
    wc.hIcon=NULL;//窗口图标句柄
    wc.hInstance=hIns;//当前模块的实例句柄
    wc.lpfnWndProc=MyWndProc;//信息处理函数的调用
    wc.lpszClassName="Main";//名字
    wc.lpszMenuName=NULL;//菜单
    wc.style=CS_HREDRAW|CS_VREDRAW;//风格//行 列变换时重新绘制//CS_HREDRAW CS_VREDRAW CS_DBLCLKS CS_NOCLOSE  |为位运算 避免重复到值进位串位
    RegisterClass(&wc);//提交结构体注册窗口
    const char *str="hello";
    HWND hWnd=CreateWindowEx(0,"Main","Welcome to my ",WS_OVERLAPPEDWINDOW,0,0,500,500,NULL,NULL,hIns,(LPVOID)str);//创建窗口并赋予给实例句柄 WS_CHILD WS_VISIBLE
    ShowWindow(hWnd,SW_SHOW);//绘制
    UpdateWindow(hWnd);//刷新
    MSG nMsg={0};
    while(GetMessage(&nMsg,NULL,0,0))
    {
        TranslateMessage(&nMsg);
        DispatchMessage(&nMsg);//消息循环
    }
   /*while(1)
   {
        if(PeekMessage(&nMsg,NULL,0,0,PM_NOREMOVE))
        {
            if(GetMessage(&nMsg,NULL,0,0))
            {
                TranslateMessage(&nMsg);
                DispatchMessage(&nMsg);
            
            else
            {
                return 0;
            }
    
        }
        else
        {
        //空闲操作
        }
   }*/
    return 0;
}

LRESULT CALLBACK MyWndProc(HWND hWnd,UINT msgID,WPARAM wParam,LPARAM lParam)//LPARAM 可以用两个宏 LOWORD HIWORD 分别获得水平坐标和垂直坐标
{
    switch(msgID)
    {
        case WM_CREATE:
        SetTimer(hWnd,1,1000,NULL);
        SetTimer(hWnd,2,2000,NULL);       
        ONCREATE(hWnd,lParam);
        break;
        case WM_TIMER:
        OnTimer(hWnd,wParam);
        break;
        case WM_SIZE:
        OnSize(hWnd,lParam);
        break;
        case WM_DESTROY:
        PostQuitMessage(0);
        //SendMessage(hWnd,WM_QUIT,0,0);
        //PostMessage(hWnd,WM_QUIT,0,0);
        break;
        case WM_PAINT:
        /*PAINTSTRUCT ps;          // 声明了局部变量
        HDC hdc = BeginPaint(hWnd, &ps);
        TextOut(hdc, 10, 10, "Hello", 5);
        EndPaint(hWnd, &ps);
        return 0;*/
        OnPaint(hWnd);
        break;
        /*case WM_LBUTTONDOWN:
        InvalidateRect(hWnd,NULL,TRUE);
        break;*/
        case WM_LBUTTONDOWN:
        OnLButtonDown(hWnd,wParam,lParam);
        break;
        case WM_MOUSEMOVE:
        OnMouseMove(hWnd,wParam,lParam);
        break;
        case WM_MOUSEWHEEL:
        OnMouseWheel(hWnd,wParam,lParam);
        break;
        case WM_KEYUP:
        OnKeyUp(hWnd,wParam);
        break;
        case WM_KEYDOWN:
        OnKeyDown(hWnd,wParam);
        break;
        case WM_SYSCOMMAND:
        if(wParam==SC_CLOSE)
        {
            int nRet=MessageBox(hWnd,"是否关闭","Information",MB_YESNO);
            if(nRet==IDNO)
            {
                return 0;
            }
            else
            {

            }
        }
        
        //case WM_MOUSE
    }
    return DefWindowProc(hWnd,msgID,wParam,lParam);
}