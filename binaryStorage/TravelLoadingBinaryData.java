package com.ankamagames.wakfu.client.binaryStorage;

public class TravelLoadingBinaryData implements dEZ {
    protected String dew;
    protected int dex;
    protected int dey;
    protected int dez;
    
    public TravelLoadingBinaryData()
    {
        super();
    }
    
    public String arF()
    {
        return this.dew;
    }
    
    public int arG()
    {
        return this.dex;
    }
    
    public int arH()
    {
        return this.dey;
    }
    
    public int arI()
    {
        return this.dez;
    }
    
    public void reset()
    {
        this.dew = null;
        this.dex = 0;
        this.dey = 0;
        this.dez = 0;
    }
    
    public void a(ceb a)
    {
        this.dew = a.clg().intern();
        this.dex = a.getInt();
        this.dey = a.getInt();
        this.dez = a.getInt();
    }
    
    final public int gZ()
    {
        throw new UnsupportedOperationException();
    }
}