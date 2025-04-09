#define NIBBLE_BIT_COUNT 4
#define NIBBLE_BM 0xF
#define NULL '\0'

void UIntToHexStr(unsigned int uiValue, char pcStr[])
{

    unsigned char ucCurrentNibbleIterator;
    unsigned char ucNibble;

    pcStr[0] = '0';
    pcStr[1] = 'x';

    for (ucCurrentNibbleIterator = 0; ucCurrentNibbleIterator < 4; ucCurrentNibbleIterator++)
    {
        ucNibble = (uiValue >> (ucCurrentNibbleIterator * NIBBLE_BIT_COUNT)) & NIBBLE_BM;
        if (ucNibble <= 9)
        {
            pcStr[5 - ucCurrentNibbleIterator] = '0' + ucNibble;
        }
        else
        {
            pcStr[5 - ucCurrentNibbleIterator] = 'A' + (ucNibble - 10);
        }
    }

    pcStr[6] = NULL;
}

enum Result { OK, ERROR };

enum Result eHexStringToUInt(char pcStr[], unsigned int* puiValue)
{

    unsigned char ucStringIterator;
    char cHexDigit;

    *puiValue = 0;

    if ((pcStr[0] != '0') || (pcStr[1] != 'x') || (pcStr[2] == NULL))
    {
        return ERROR;
    }

    for (ucStringIterator = 2; pcStr[ucStringIterator] != NULL; ucStringIterator++)
    {
        cHexDigit = pcStr[ucStringIterator];

        if (cHexDigit >= 'A')
        {
            *puiValue = *puiValue << NIBBLE_BIT_COUNT;
            *puiValue = *puiValue + (((cHexDigit - 'A') + 10) & NIBBLE_BM);
        }
        else
        {
            *puiValue = *puiValue << NIBBLE_BIT_COUNT;
            *puiValue = *puiValue + ((cHexDigit - '0') & NIBBLE_BM);
        }
    }

    if (ucStringIterator > 6) {
        return ERROR;
    }

    return OK;
}

void AppendUIntToString(unsigned int uiValue, char pcDestinationStr[])
{

    unsigned char ucStringIterator;

    for (ucStringIterator = 0; pcDestinationStr[ucStringIterator] != NULL; ucStringIterator++)
    {

    }

    UIntToHexStr(uiValue, pcDestinationStr + ucStringIterator);
}

int main(void)
{
	while(1)
	{
	}
	
	return 0;
}