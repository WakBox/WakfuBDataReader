package com.ankamagames.wakfu.client.binaryStorage;

public class AchievementListBinaryData implements dEZ {
    protected int az;
    protected dkH[] giO;
    
    public AchievementListBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public dkH[] bId()
    {
        return this.giO;
    }
    
    public void reset()
    {
        this.az = 0;
        this.giO = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.getInt();
        this.giO = new dkH[i];
        int i0 = 0;
        while(i0 < i)
        {
            this.giO[i0] = new dkH();
            this.giO[i0].a(a);
            i0 = i0 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eFA.getId();
    }
}