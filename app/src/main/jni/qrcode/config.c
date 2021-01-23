#include <config.h>
#include <stdlib.h>
#include <string.h>
#ifdef HAVE_ERRNO_H
# include <errno.h>
#endif

#include <zbar.h>

int zbar_parse_config (const char *cfgstr,
                       zbar_symbol_type_t *sym,
                       zbar_config_t *cfg,
                       int *val)
{
    const char *dot, *eq;
    int len;
    char negate;
    if(!cfgstr)
        return(1);

    dot = strchr(cfgstr, '.');
    if(dot) {
        int len = dot - cfgstr;
        if(!len || (len == 1 && !strncmp(cfgstr, "*", len)))
            *sym = 0;
        else if(len < 2)
            return(1);
        else if(!strncmp(cfgstr, "qrcode", len))
            *sym = ZBAR_QRCODE;
        else if(!strncmp(cfgstr, "db", len))
            *sym = ZBAR_DATABAR;
        else if(len < 3)
            return(1);
        else if(!strncmp(cfgstr, "upca", len))
            *sym = ZBAR_UPCA;
        else if(!strncmp(cfgstr, "upce", len))
            *sym = ZBAR_UPCE;
        else if(!strncmp(cfgstr, "ean13", len))
            *sym = ZBAR_EAN13;
        else if(!strncmp(cfgstr, "ean8", len))
            *sym = ZBAR_EAN8;
        else if(!strncmp(cfgstr, "ean5", len))
            *sym = ZBAR_EAN5;
        else if(!strncmp(cfgstr, "ean2", len))
            *sym = ZBAR_EAN2;
        else if(!strncmp(cfgstr, "composite", len))
            *sym = ZBAR_COMPOSITE;
        else if(!strncmp(cfgstr, "i25", len))
            *sym = ZBAR_I25;
        else if(len < 4)
            return(1);
        else if(!strncmp(cfgstr, "scanner", len))
            *sym = ZBAR_PARTIAL;
        else if(!strncmp(cfgstr, "isbn13", len))
            *sym = ZBAR_ISBN13;
        else if(!strncmp(cfgstr, "isbn10", len))
            *sym = ZBAR_ISBN10;
        else if(!strncmp(cfgstr, "db-exp", len))
            *sym = ZBAR_DATABAR_EXP;
        else if(!strncmp(cfgstr, "codabar", len))
            *sym = ZBAR_CODABAR;
        else if(len < 6)
            return(1);
        else if(!strncmp(cfgstr, "code93", len))
            *sym = ZBAR_CODE93;
        else if(!strncmp(cfgstr, "code39", len))
            *sym = ZBAR_CODE39;
        else if(!strncmp(cfgstr, "pdf417", len))
            *sym = ZBAR_PDF417;
        else if(len < 7)
            return(1);
        else if(!strncmp(cfgstr, "code128", len))
            *sym = ZBAR_CODE128;
        else if(!strncmp(cfgstr, "databar", len))
            *sym = ZBAR_DATABAR;
        else if(!strncmp(cfgstr, "databar-exp", len))
            *sym = ZBAR_DATABAR_EXP;
        else
            return(1);
        cfgstr = dot + 1;
    }
    else
        *sym = 0;

    len = strlen(cfgstr);
    eq = strchr(cfgstr, '=');
    if(eq)
        len = eq - cfgstr;
    else
        *val = 1;
    negate = 0;

    if(len > 3 && !strncmp(cfgstr, "no-", 3)) {
        negate = 1;
        cfgstr += 3;
        len -= 3;
    }

    if(len < 1)
        return(1);
    else if(!strncmp(cfgstr, "y-density", len))
        *cfg = ZBAR_CFG_Y_DENSITY;
    else if(!strncmp(cfgstr, "x-density", len))
        *cfg = ZBAR_CFG_X_DENSITY;
    else if(len < 2)
        return(1);
    else if(!strncmp(cfgstr, "enable", len))
        *cfg = ZBAR_CFG_ENABLE;
    else if(len < 3)
        return(1);
    else if(!strncmp(cfgstr, "disable", len)) {
        *cfg = ZBAR_CFG_ENABLE;
        negate = !negate;
    }
    else if(!strncmp(cfgstr, "min-length", len))
        *cfg = ZBAR_CFG_MIN_LEN;
    else if(!strncmp(cfgstr, "max-length", len))
        *cfg = ZBAR_CFG_MAX_LEN;
    else if(!strncmp(cfgstr, "ascii", len))
        *cfg = ZBAR_CFG_ASCII;
    else if(!strncmp(cfgstr, "add-check", len))
        *cfg = ZBAR_CFG_ADD_CHECK;
    else if(!strncmp(cfgstr, "emit-check", len))
        *cfg = ZBAR_CFG_EMIT_CHECK;
    else if(!strncmp(cfgstr, "uncertainty", len))
        *cfg = ZBAR_CFG_UNCERTAINTY;
    else if(!strncmp(cfgstr, "position", len))
        *cfg = ZBAR_CFG_POSITION;
    else
        return(1);

    if(eq) {
#ifdef HAVE_ERRNO_H
        errno = 0;
#endif
        *val = strtol(eq + 1, NULL, 0);
#ifdef HAVE_ERRNO_H
        if(errno)
            return(1);
#endif
    }
    if(negate)
        *val = !*val;

    return(0);
}
