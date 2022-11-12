#ifndef CHARACTERVIEW_H
#define CHARACTERVIEW_H


class CharacterView
{
    public:
        CharacterView();
        virtual ~CharacterView();
        CharacterView(const CharacterView& other);
        CharacterView& operator=(const CharacterView& other);

    protected:

    private:
};

#endif // CHARACTERVIEW_H
