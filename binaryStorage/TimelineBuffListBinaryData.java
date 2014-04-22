package com.ankamagames.wakfu.client.binaryStorage;

public class TimelineBuffListBinaryData implements dEZ {
    protected int az;
    protected int beC;
    protected int aZE;
    protected int[] bav;
    
    public TimelineBuffListBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int yA()
    {
        return this.beC;
    }
    
    public int oM()
    {
        return this.aZE;
    }
    
    public int[] wK()
    {
        return this.bav;
    }
    
    public void reset()
    {
        this.az = 0;
        this.beC = 0;
        this.aZE = 0;
        this.bav = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.beC = a.getInt();
        this.aZE = a.getInt();
        this.bav = a.cli();
    }
    
    final public int gZ()
    {
        return aPw.eEK.getId();
    }
}