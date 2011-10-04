/**
 * @file 	usbprint.c
 * @author 	MAAOUI Wael
 * @date 	2007-11-22
 *
 * @brief  	module to manage usb printer
 *
 * @par 	Modifications
 *
 *
 * @par 	Licences
 *   		Copyright (C) 2000-2007 SAFRAN
 *   		All rights reserved
 *
 */
////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Include necessary standard headers...
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <sys/types.h>

 /**
 * Include necessary custom headers...
 */



#define PREFIX_LOCK_FILE  		    "/var/lock/lock_"
#define PREFIX_DEVICE_NODE          "usblp"
#define LOCK_FILE_LENGTH            32
#define USB_PRINTER                 "/dev/usblp0" /* USB Port */
#define LOCK_FILE 		    "/var/lock/lock_usblp0"

int usbPrintOpen(const char * p_printer_path);
void usbPrintClose(int fd, const char * p_printer_path);
static void get_lock_file(const char * p_printer_path, char lock_file[LOCK_FILE_LENGTH]);


/*******************************************************************************
* Public  Functions implementation
*******************************************************************************/

 /**
  * @brief 		open usb device and create the file lock
  * @param 		p_printer_path : a pointer to the printer path to get the name
  *                             of the lock file
  * @returns 	the file descriptor of the printer device node
  **/
int usbPrintOpen(const char * p_printer_path)
{  
	struct stat state;
    char lock_file [LOCK_FILE_LENGTH] = PREFIX_LOCK_FILE;
	int usb_fd = -1;             /* usb file descriptor */
   
   get_lock_file(p_printer_path, lock_file);
    	
	if (lstat(lock_file,&state) != 0)
	{	
		creat(lock_file,S_IRWXU);
		usb_fd = open(p_printer_path,O_WRONLY|O_SYNC);
	}
    
	return usb_fd; 
      
}

 /**
  * @brief 		close usb device and delete the lock file
  * @param 		fd : the file descriptor of the printer device node
  * @param      p_printer_path : a pointer to the printer path to get the name
  *                             of the file lock
  * @returns 	none
  **/
void usbPrintClose(int fd, const char * p_printer_path)
{
    char lock_file [LOCK_FILE_LENGTH] = PREFIX_LOCK_FILE;
    
    close(fd);
    get_lock_file(p_printer_path, lock_file);
    unlink(lock_file);
}



/*******************************************************************************
* local  Functions implementation
*******************************************************************************/

 /**
  * @brief      return the name of the lock file
  * @param      p_printer_path : a pointer to the printer path
  * @param      p_lock_file    : a pointer to the lock file
  * @returns    none
  **/
static void get_lock_file(const char * p_printer_path, char * p_lock_file)
{
    char * device_node;
    
    device_node = strrchr(p_printer_path, '/') + 1;
    strncat(p_lock_file,device_node,strlen(device_node));
    
}

