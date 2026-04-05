bool judgeCircle(char* moves) {
    int column=0;
    int row=0;
    for (int i=0;moves[i]!='\0';i++)
    {
        if(moves[i]=='U')
        {
            column++;
        }
        else if(moves[i]=='D')
        {
            column--;
        }
        else if(moves[i]=='L')
        {
            row--;
        }
        else if(moves[i]=='R')
        {
            row++;
        }
    }
    if(column==0&&row==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}