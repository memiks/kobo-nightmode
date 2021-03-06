//Configuration
#define		SI_CONTROL_PIPE		"/tmp/invertScreen"
#define		SI_CONFIG_FILE		"/mnt/onboard/.kobo/nightmode.ini"
#define 	SI_DEBUG_LOGPATH    "/mnt/onboard/.kobo/screenInvertLog"
#define		SI_AREA_THRESHOLD	60	//percent

static char log_filename[50] = "";

//for logging, compile with "make debug"
#ifdef SI_DEBUG
#define DEBUGPRINT(_fmt, ...) \
        do { \
        	if(strlen(log_filename)<1) \
        		sprintf(log_filename, "%s_%ld", SI_DEBUG_LOGPATH, time(NULL)); \
            FILE *logFP = fopen_orig(log_filename, "a"); \
            struct timeval tm; \
            time_t nowtime; \
            struct tm *nowtm; \
            char tmbuf[64]; \
            gettimeofday(&tm, NULL); \
            nowtime = tm.tv_sec; \
            nowtm = localtime(&nowtime); \
            strftime(tmbuf, sizeof tmbuf, "%Y/%m/%d %H:%M:%S", nowtm); \
            if(logFP) { fprintf(logFP, "[%s.%06ld] ", tmbuf, (long int)tm.tv_usec); \
			fprintf(logFP, _fmt, ##__VA_ARGS__); \
			fprintf(logFP, "\n"); \
            fclose(logFP); } \
       } while (0)
#else
#define DEBUGPRINT(_fmt, ...) /**/
#endif
