// Copyright CircumScriptor and DarkNeutrino 2021
#ifndef TYPES_H
#define TYPES_H

#define LOG_DEBUG(msg, ...)  printf("DEBUG: " msg "\n", ##__VA_ARGS__)
#define LOG_INFO(msg, ...)  printf("INFO: " msg "\n", ##__VA_ARGS__)
#define LOG_STATUS(msg, ...)  printf("STATUS: " msg "\n", ##__VA_ARGS__)
#define LOG_WARNING(msg, ...) printf("WARNING: " msg "\n", ##__VA_ARGS__)
#define LOG_ERROR(msg, ...)   fprintf(stderr, "ERROR: " msg "\n", ##__VA_ARGS__)

typedef unsigned char          uint8;
typedef unsigned short         uint16;
typedef unsigned int           uint32;
typedef unsigned long long int uint64;

typedef union
{
    uint8 colorArray[4];
    uint32 color;
} Color4i;

typedef union
{
    uint8 colorArray[3];
    uint32 color; //Bitshift required before usage
} Color3i;

typedef struct
{
    float x;
    float y;
} Vector2f;

typedef struct
{
    float x;
    float y;
    float z;
} Vector3f;

typedef struct
{
    long x;
    long y;
    long z;
} Vector3l;

typedef struct
{
    int x;
    int y;
    int z;
} Vector3i;

typedef struct
{
    Vector3f from;
    Vector3f to;
} Quad3D;

#endif /* TYPES_H */
