typedef struct {
    unsigned char *streams[22];
    signed char stream_index;
} Object;

unsigned char func_8003B7E0(Object *object)
{
    return *object->streams[object->stream_index]++;
}
