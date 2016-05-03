#ifndef PA5GAME_ERRORCONTEXT_H
#define PA5GAME_ERRORCONTEXT_H

#include <iostream>
#include <set>
#include <sstream>

namespace Testing {

    using std::set;
    using std::ostream;
    using std::string;

    class ErrorContext              
    {
    public:
        ErrorContext(ostream &os);              
        void desc(const char *msg, int line);  
        void desc(string msg, int line);

        void result(bool good);                 
        ~ErrorContext();                        
        bool ok() const;                        

    private:
        ostream &os;                            
        int passed;                             
        int total;                             
        int lastline;                           
        set<int> badlines;                      
        bool skip;                              
    };

}


#endif //PA5GAME_ERRORCONTEXT_H
