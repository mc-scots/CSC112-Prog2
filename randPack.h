// This is a random pack of random alpacas.
// Note how this is in its own namespace!
#include "alpacaFracasPack.h"

namespace randPack {
    class FracasPack : public AlpacaFracasPack {
        public:
        FracasPack();
        virtual std::string name();

        private:
        std::string packName;
    };
};