package com.ankamagames.wakfu.client.binaryStorage;

public class DungeonDisplayerInteractiveElementParamBinaryData implements dEZ {
    protected int az;
    protected int esC;
    
    public DungeonDisplayerInteractiveElementParamBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int aWQ()
    {
        return this.esC;
    }
    
    public void reset()
    {
        this.az = 0;
        this.esC = 0;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.esC = a.getInt();
    }
    
    final public int gZ()
    {
        return aPw.eFg.getId();
    }
}