class ControlHandler{
    private:
        uint64_t keyPressCount         = 0;    // Presses
        uint64_t mouseClickCount       = 0;    // Clicks
        uint64_t mouseTravelDistance   = 0;    // Pixels
        uint64_t mouseDragDistance     = 0;    // Pixels

    public:
        void keyboardDownEvent(unsigned char, int, int);
        void keyboardUpEvent(unsigned char, int, int);
        void mouseClickEvent(int, int, int, int);
        void mouseMoveEvent(int, int);
        void mouseDragEvent(int, int);
};

void ControlHandler::keyboardDownEvent(unsigned char key, int x, int y){
    keyPressCount++;
}

void ControlHandler::keyboardUpEvent(unsigned char key, int x, int y){
    
}

void ControlHandler::mouseClickEvent(int b, int s, int x, int y){
    mouseClickCount++;
}

void ControlHandler::mouseMoveEvent(int x, int y){
    mouseTravelDistance++;
}

void ControlHandler::mouseDragEvent(int x, int y){
    mouseDragDistance++;
}