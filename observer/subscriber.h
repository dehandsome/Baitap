#ifndef SUBSCRIBERS_H
#define SUBSCRIBERS_H

typedef struct Publisher Publisher;
typedef struct Subscriber
{
    void (*update)(struct Subscriber* self, Publisher* context, const char* eventInfo);
    void* data;
}Subscriber;


#endif