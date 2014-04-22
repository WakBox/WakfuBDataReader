package com.ankamagames.wakfu.client.binaryStorage;

public class AchievementVariableBinaryData implements dEZ {
    protected int az;
    protected String m_name;
    
    public AchievementVariableBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public String getName()
    {
        return this.m_name;
    }
    
    public void reset()
    {
        this.az = 0;
        this.m_name = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.m_name = a.clg().intern();
    }
    
    final public int gZ()
    {
        return aPw.eDr.getId();
    }
}