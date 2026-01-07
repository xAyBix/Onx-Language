#include <stdio.h>
#include <string.h>
#include "commands/easter_eggs.h"

#ifdef _WIN32
    #include <windows.h>
    
    void sleep_ms(int milliseconds)
    {
        Sleep(milliseconds);
    }
    
    int is_running_as_admin(void)
    {
        BOOL is_admin = FALSE;
        PSID admin_group = NULL;
        SID_IDENTIFIER_AUTHORITY nt_authority = SECURITY_NT_AUTHORITY;
        
        if (AllocateAndInitializeSid(&nt_authority, 2,
                                      SECURITY_BUILTIN_DOMAIN_RID,
                                      DOMAIN_ALIAS_RID_ADMINS,
                                      0, 0, 0, 0, 0, 0,
                                      &admin_group)) 
        {
            CheckTokenMembership(NULL, admin_group, &is_admin);
            FreeSid(admin_group);
        }
        
        return is_admin;
    }
#else
    #include <unistd.h>
    
    void sleep_ms(int milliseconds)
    {
        usleep(milliseconds * 1000);
    }
    
    int is_running_as_admin(void) 
    {
        return geteuid() == 0;
    }
#endif



void make_sandwich(void) 
{
    printf("\033[38;5;208mOnx>> \033[0m");
    fflush(stdout);
    
    if (is_running_as_admin()) 
    {
        const char *agree = "*SIGH*, making a sandwich...\n";
        int len = strlen(agree);
        for (int i = 0; i < len; i++) 
        {
            if (agree[i] == '.')
            {
                sleep_ms(1000);
            }else if (agree[i] == ',')
            {
                printf("%c", agree[i]);
                fflush(stdout);
                sleep_ms(1000);
                continue;
            }else if (agree[i] == ' ')
            {
                printf("%c", agree[i]);
                fflush(stdout);
                sleep_ms(200);
                continue;
            }else 
            {
                sleep_ms(90);
            }
            printf("%c", agree[i]);
            fflush(stdout);
        }
        printf("\n\n");
        printf("                    _.---._\n");
        printf("                _.-~       ~-._\n");
        printf("            _.-~               ~-._\n");
        printf("        _.-~                       ~---._\n");
        printf("    _.-~                                 ~\\\n");
        printf(" .-~                                    _.;\n");
        printf(" :-._                               _.-~ ./\n");
        printf(" }-._~-._                   _..__.-~ _.-~)\n");
        printf(" `-._~-._~-._              / .__..--~_.-~\n");
        printf("     ~-._~-._\\.        _.-~_/ _..--~~\n");
        printf("         ~-. \\`--...--~_.-~/~~\n");
        printf("            \\.`--...--~_.-~\n");
        printf("              ~-..----~\n");
        printf("\n");
    } 
    else 
    {
        printf("What? Make it yourself.\n");
    }
}

void hello_world(void) 
{
     printf("\033[38;5;208mOnx>> \033[0mAh, the classic! May your journey into \033[38;5;208mOnx \033[0mbe legendary.\n");
     fflush(stdout);
}

void upside_down(void)
{
    printf("ʇsᴉsǝɹ ʇ,uplnoɔ ᴉ ʎɹɹoS \033[38;5;208m<<xuO\033[0m\n");
    fflush(stdout);
}