#ifndef PLAYSTATEVIEW_H
#define PLAYSTATEVIEW_H


class PlayStateView
{
    public:
        PlayStateView();
        virtual ~PlayStateView();
        PlayStateView(const PlayStateView& other);
        PlayStateView& operator=(const PlayStateView& other);

    protected:

    private:
};

#endif // PLAYSTATEVIEW_H
