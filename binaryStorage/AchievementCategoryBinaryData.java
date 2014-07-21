package com.ankamagames.wakfu.client.binaryStorage;

public class AchievementCategoryBinaryData implements dEZ {
    protected int az;
    protected int biA;
    
    public AchievementCategoryBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int AF()
    {
        return this.biA;
    }
    
    public void reset()
    {
        this.az = 0;
        this.biA = 0;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.biA = a.getInt();
    }
    
    final public int gZ()
    {
        return aPw.eDs.getId();
    }
}