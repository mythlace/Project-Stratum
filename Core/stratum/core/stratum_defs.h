/**
 * @file stratum_defs.h
 *
 * @date Mar 8, 2026
 * @author mdev 
 */


#pragma once
#ifdef __cplusplus
 extern "C" {
#endif

 /**
  *
  */
typedef enum {
	STRATUM_ERR_ASSERTION = -3,
	STRATUM_ERR_FATAL = -2,
	STRATUM_ERR_UNKNOWN = -1,

	STRATUM_STATUS_OK = 0,
	STRATUM_STATUS_UNKNOWN = 1,
} stratum_status_t;



#ifdef __cplusplus
}
#endif
