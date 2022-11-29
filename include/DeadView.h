#ifndef DEADVIEW_H
#define DEADVIEW_H


class DeadView
{
    public:
        DeadView();
        virtual ~DeadView();
        DeadView(const DeadView& other);
        DeadView& operator=(const DeadView& other);

    protected:

    private:
};

#endif // DEADVIEW_H
