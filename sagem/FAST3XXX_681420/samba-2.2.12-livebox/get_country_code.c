///////////////////////////////////////////////////////////////////////////////
/**
 * @file    
 * @brief
 * @note    SAGEM Software & Technologies - SST
 * @author  Wael MAAOUI
 * @date    2008-09-17
 * @par     Licences
 * @note    CopyRight (C) 2000-2008 SST
 * @version
 */
///////////////////////////////////////////////////////////////////////////////
///
/// INCLUDE
///
#include <stdlib.h>
#include <stdio.h>

#include "flashinfos.h"





/*  get label by country */

int main (int argc,char *argv[])
{
    char _permanentParameterCountry[MAX_PERMPARAMS_CTRY_SIZE];
     
    if (getCountry(_permanentParameterCountry, MAX_PERMPARAMS_CTRY_SIZE) !=
                        PERM_PARAMS_OK)
    {
        return -1;
    }

    printf("%s", _permanentParameterCountry );
   
return 0;
}









