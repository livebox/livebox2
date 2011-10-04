///////////////////////////////////////////////////////////////////////////////
/**
 * @file
 * @brief
 * @note    SAGEM Software & Technologies - SST
 * @author  Wael MAAOUI
 * @date    2008-04-29
 * @par     Licences
 * @note    CopyRight (C) 2000-2008 SST
 * @version
 */
///////////////////////////////////////////////////////////////////////////////
///
/// INCLUDE
///


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <glob.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>




///////////////////////////////////////////////////////////////////////////////
///
/// MACROS
///


#ifdef __DEBUG__
#define DEBUG(message, args...)     printf("%s/%s:%d=> "message"\n",__FILE__, __FUNCTION__, __LINE__, ##args)
#else
#define DEBUG(message, args...)
#endif // __DEBUG__

#define FAILURE  -1
#define SUCCESS   0


#ifdef _DYNAMIC
#define GLOB_PATTERN "/proc/[0-9]*/cwd"
#else
#define GLOB_PATTERN "/proc/[0-9]*/fd/[0-9]*"
#endif

#define MAX_PATH_SIZE 256
#define MAX_PID_LENGTH  4
static glob_t globbuf_process;


static void usage(const char *);
static void kill_static_share(char *proc_path,char *link,char *mounting_point);
static void kill_dynamic_share(char *proc_path,char *link,char *mounting_point);
/**
 * @brief  this function shows the program usage
 * @author Wael MAAOUI
 * @param  main_program :program name
 * @returns void
 */

static void usage(const char *main_program)
{
    fprintf(stdout, "Usage :\n\t\%s  <Mounting path>\tFor Killing <Mounting path> Process (compile with -D_DYNAMIC for dynamic share)\n",main_program);
}

/**
 * @brief  this function kill the process which file descriptor
 * @brief  points into a mounting_point
 * @author Wael MAAOUI
 * @param  : proc_path : result of glob
 * @param  : link : the link of proc_path
 * @param  : mounting_point : mounting point
 * @returns void
 */


static void kill_static_share(char *proc_path,char *link,char *mounting_point)
{
	char  path[MAX_PATH_SIZE]="";
	char *proc_pid=NULL;
    char *s=NULL;

	assert(proc_path !=NULL);
    assert(link !=NULL);
    assert(mounting_point !=NULL);

	   if (strstr(link,mounting_point)!=NULL)
        {
            strcpy(path,proc_path);
            s=strstr(path,"/fd/");
            path[strlen(path)-strlen(s)]='\0';
            proc_pid=strrchr(path, '/') + 1;
            kill (atoi(proc_pid),SIGTERM);
        }


}

/**
 * @brief  this function kill the process which current working directory
 * @brief  points into a mounting_point
 * @author Wael MAAOUI
 * @param  : proc_path : result of glob
 * @param  : link : the link of proc_path
 * @param  : mounting_point : mounting point
 * @returns void
 */


static void kill_dynamic_share(char *proc_path,char *link,char *mounting_path)
{
	char  path[MAX_PATH_SIZE]="";
	char *proc_pid=NULL;


	assert(proc_path !=NULL);
    assert(link !=NULL);
    assert(mounting_path !=NULL);

    if (strcmp(link,mounting_path)==0)
    {
        strcpy(path,proc_path);
        path[strlen(path)-4]='\0';
        proc_pid=strrchr(path, '/') + 1;
        kill (atoi(proc_pid),SIGTERM);
    }
}






int main(int argc, char *argv[])
{


    int i;
    char link[MAX_PATH_SIZE]="";

    if(argc != 2) { /* Incorrect Usage */
       usage(argv[0]);
	   return FAILURE;
    }


    assert(argv[1] != NULL);


        if ((glob(GLOB_PATTERN, GLOB_DOOFFS | GLOB_ONLYDIR | GLOB_MARK, NULL, &globbuf_process)) != 0)
        {
            DEBUG("No Matching Found,%d\n",globbuf_process.gl_pathc);
            return FAILURE;
        }
        for (i=0; i<globbuf_process.gl_pathc; i++)

        {
            memset(link,0,MAX_PATH_SIZE);
            readlink(globbuf_process.gl_pathv[i],link,strlen(argv[1]));
            #ifdef _DYNAMIC
            kill_dynamic_share(globbuf_process.gl_pathv[i],link,argv[1]);
            #else
            kill_static_share(globbuf_process.gl_pathv[i],link,argv[1]);
            #endif


        }


 globfree(&globbuf_process);
    return SUCCESS;


}
