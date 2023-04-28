// Defines UEFI Status codes

#ifndef __EFI_STATUS_CODES__
#define __EFI_STATUS_CODES__

// DEPENDENCIES

#ifndef __EFI_DATA_TYPES__
#include "DataTypes.h"
#endif //__EFI_DATA_TYPES__

// PROTOTYPES

#define MAX_BIT (uintmax_t) 1 << (sizeof(uintmax_t) * 8 - 1)
#define ENCODE_ERROR(StatusCode) ((uintmax_t)(MAX_BIT | (StatusCode)))
#define ENCODE_WARNING(StatusCode) ((uintmax_t)(StatusCode))

#define EFI_SUCCESS 0

#define EFI_WARN_UNKNOWN_GLYPH      ENCODE_WARNING (1)
#define EFI_WARN_DELETE_FAILURE     ENCODE_WARNING (2)
#define EFI_WARN_WRITE_FAILURE      ENCODE_WARNING (3)
#define EFI_WARN_BUFFER_TOO_SMALL   ENCODE_WARNING (4)
#define EFI_WARN_STALE_DATA         ENCODE_WARNING (5)
#define EFI_WARN_FILE_SYSTEM        ENCODE_WARNING (6)
#define EFI_WARN_RESET_REQUIRED     ENCODE_WARNING (7)

#define EFI_LOAD_ERROR              ENCODE_ERROR (1)
#define EFI_INVALID_PARAMETER       ENCODE_ERROR (2)
#define EFI_UNSUPPORTED             ENCODE_ERROR (3)
#define EFI_BAD_BUFFER_SIZE         ENCODE_ERROR (4)
#define EFI_BUFFER_TOO_SMALL        ENCODE_ERROR (5)
#define EFI_NOT_READY               ENCODE_ERROR (6)
#define EFI_DEVICE_ERROR            ENCODE_ERROR (7)
#define EFI_WRITE_PROTECTED         ENCODE_ERROR (8)
#define EFI_OUT_OF_RESOURCES        ENCODE_ERROR (9)
#define EFI_VOLUME_CORRUPTED        ENCODE_ERROR (10)
#define EFI_VOLUME_FULL             ENCODE_ERROR (11)
#define EFI_NO_MEDIA                ENCODE_ERROR (12)
#define EFI_MEDIA_CHANGED           ENCODE_ERROR (13)
#define EFI_NOT_FOUND               ENCODE_ERROR (14)
#define EFI_ACCESS_DENIED           ENCODE_ERROR (15)
#define EFI_NO_RESPONSE             ENCODE_ERROR (16)
#define EFI_NO_MAPPING              ENCODE_ERROR (17)
#define EFI_TIMEOUT                 ENCODE_ERROR (18)
#define EFI_NOT_STARTED             ENCODE_ERROR (19)
#define EFI_ALREADY_STARTED         ENCODE_ERROR (20)
#define EFI_ABORTED                 ENCODE_ERROR (21)
#define EFI_ICMP_ERROR              ENCODE_ERROR (22)
#define EFI_TFTP_ERROR              ENCODE_ERROR (23)
#define EFI_PROTOCOL_ERROR          ENCODE_ERROR (24)
#define EFI_INCOMPATIBLE_VERSION    ENCODE_ERROR (25)
#define EFI_SECURITY_VIOLATION      ENCODE_ERROR (26)
#define EFI_CRC_ERROR               ENCODE_ERROR (27)
#define EFI_END_OF_MEDIA            ENCODE_ERROR (28)
#define EFI_END_OF_FILE             ENCODE_ERROR (31)
#define EFI_INVALID_LANGUAGE        ENCODE_ERROR (32)
#define EFI_COMPROMISED_DATA        ENCODE_ERROR (33)
#define EFI_IP_ADDRESS_CONFLICT     ENCODE_ERROR (34)
#define EFI_HTTP_ERROR              ENCODE_ERROR (35)

#endif //__EFI_STATUS_CODES__