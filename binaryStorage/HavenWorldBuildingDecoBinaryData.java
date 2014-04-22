package com.ankamagames.wakfu.client.binaryStorage;

public class HavenWorldBuildingDecoBinaryData implements dEZ {
    protected int az;
    protected short hvt;
    protected int cMg;
    protected int hGe;
    protected int hGg;
    
    public HavenWorldBuildingDecoBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public short cfA()
    {
        int i = this.hvt;
        return (short)i;
    }
    
    public int alf()
    {
        return this.cMg;
    }
    
    public int cjP()
    {
        return this.hGe;
    }
    
    public int bjU()
    {
        return this.hGg;
    }
    
    public void reset()
    {
        this.az = 0;
        this.hvt = (short)0;
        this.cMg = 0;
        this.hGe = 0;
        this.hGg = 0;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.getShort();
        this.hvt = (short)i;
        this.cMg = a.getInt();
        this.hGe = a.getInt();
        this.hGg = a.getInt();
    }
    
    final public int gZ()
    {
        return aPw.eFL.getId();
    }
}