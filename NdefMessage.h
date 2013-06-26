#ifndef NdefMessage_h
#define NdefMessage_h

#include <Ndef.h>
#include <NdefRecord.h>

#define MAX_NDEF_RECORDS 4

class NdefMessage
{
    public:
        NdefMessage(void);
        NdefMessage(const byte *data, const int numBytes);  
        NdefMessage(const NdefMessage& rhs);  
        ~NdefMessage();     
        NdefMessage& operator=(const NdefMessage& rhs);
        
        int getEncodedSize(); // need so we can pass array to encode
        void encode(byte *data);
        // TODO encode(uint8_t* data, int numberBytes); ???

        boolean addRecord(NdefRecord& record);
        void addMimeMediaRecord(String mimeType, String payload);
        void addMimeMediaRecord(String mimeType, byte *payload, int payloadLength);
        void addTextRecord(String text);
        void addTextRecord(String text, String encoding);
        void addUriRecord(String uri);
        void addEmptyRecord();

        uint8_t getRecordCount();
        NdefRecord getRecord(int index);
        NdefRecord operator[](int index);

        void print();
    private:
        NdefRecord _records[MAX_NDEF_RECORDS];
        uint8_t _recordCount;
};

#endif