package com.ankamagames.wakfu.client.binaryStorage;

public class KrosmozFigureBinaryData implements dEZ {
    protected int az;
    protected int hkA;
    protected int hkB;
    protected int ciV;
    
    public KrosmozFigureBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int getYear()
    {
        return this.hkA;
    }
    
    public int bZO()
    {
        return this.hkB;
    }
    
    public int bZP()
    {
        return this.ciV;
    }
    
    public void reset()
    {
        this.az = 0;
        this.hkA = 0;
        this.hkB = 0;
        this.ciV = 0;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.hkA = a.getInt();
        this.hkB = a.getInt();
        this.ciV = a.getInt();
    }
    
    final public int gZ()
    {
        return aPw.eFy.getId();
    }
}