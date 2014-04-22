package com.ankamagames.wakfu.client.binaryStorage;

public class TutorialBinaryData implements dEZ {
    protected int az;
    protected bKK[] cNK;
    
    public TutorialBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public bKK[] alQ()
    {
        return this.cNK;
    }
    
    public void reset()
    {
        this.az = 0;
        this.cNK = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.getInt();
        this.cNK = new bKK[i];
        int i0 = 0;
        while(i0 < i)
        {
            this.cNK[i0] = new bKK();
            this.cNK[i0].a(a);
            i0 = i0 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eFO.getId();
    }
}