#ifndef LL_CLASSES_H
#define LL_CLASSES_H

#include <list>
#include <mutex>
#include <condition_variable>

#include "define.h"

#include "libavutil/frame.h"
#include "libavcodec/avcodec.h"

using namespace std;

struct Frame
{
    AVFrame *frame;
    AVSubtitle sub;
    int serial;
    double pts;           /* presentation timestamp for the frame */
    double duration;      /* estimated duration of the frame */
    int64_t pos;          /* byte position of the frame in the input file */
    int width;
    int height;
    int format;
    AVRational sar;
    int uploaded;
    int flip_v;
};

class PacketQueue;

struct FrameQueue
{
    Frame queue[FRAME_QUEUE_SIZE];
    int rindex;
    int windex;
    int size;
    int max_size;
    int keep_last;
    int rindex_shown;
    mutex mutex;
    condition_variable *cond;
    PacketQueue *pktq;
};

class PacketQueue
{
public:
    
    size_t size() const
    {
        return m_pkts.size();
    }
    
private:
    
    list<void*> m_pkts;
    
    mutex m_mutex;
    condition_variable m_cond;
};

#endif
