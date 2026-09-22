#ifndef GRAPHICSPRESENTATION_H_
#define GRAPHICSPRESENTATION_H_


class graphicspresentation {
public:
    virtual ~graphicspresentation() = default;
public:
    virtual bool init() = 0;
    virtual void acquire() = 0;
    virtual void present() = 0;

private:
    // api-specific stuff
};


#endif // GRAPHICSPRESENTATION_H_