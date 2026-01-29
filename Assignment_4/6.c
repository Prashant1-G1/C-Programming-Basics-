#include <stdio.h> 

int Total_click=0;

void Session_click(int Clicks_per_session)
{
    static int session_count=0;

    for (int i=1; i<=Clicks_per_session; i++)
    {
        session_count++;
        Total_click++;

        printf("Click %d in this session (Session_count = %d, Total_clicks = %d)\n" , i ,session_count,Total_click); 
    }
}

int main()
{
    printf("=============================First Session======================\n");
    Session_click(5);

    printf("\n===========================Second Session======================\n");
    Session_click(5);

    printf("\nTotal Clicks in all Session = %d",Total_click);

    return 0;
}