/*
 * intlist.h
 *
 * Beispielprogramm eingebettete Klassen.
 *
 * Autor: H.Drachenfels
 * Erstellt am: 10.2.2021
 */
#ifndef INTLIST_H
#define INTLIST_H

class intlist final
{
private:
    class element;
    element *head;

public:
    intlist();
    ~intlist();
    // Entity-Klasse ohne Kopier- und Move-Semantik
    intlist(const intlist&) = delete;
    intlist& operator=(const intlist&) = delete;
    intlist(intlist&&) = delete;
    intlist& operator=(intlist&&) = delete;

    intlist& insert(int);

    class iterator final
    {
    private:
        element *current;
        explicit iterator(element*);
    public:
        bool operator!=(const iterator&) const;
        int& operator*() const;
        iterator& operator++();

        friend class intlist;
    };

    iterator begin();
    iterator end();
};

#endif

