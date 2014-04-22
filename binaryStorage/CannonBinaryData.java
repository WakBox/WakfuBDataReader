package com.ankamagames.wakfu.client.binaryStorage;

public class CannonBinaryData implements dEZ {
    protected int mok;
    protected int UA;
    protected int bQK;
    protected byte fsb;
    protected int Uo;
    protected int lMU;
    protected cGR[] mol;
    
    public CannonBinaryData()
    {
        super();
    }
    
    public int dsx()
    {
        return this.mok;
    }
    
    public int gX()
    {
        return this.UA;
    }
    
    public int Or()
    {
        return this.bQK;
    }
    
    public byte brI()
    {
        int i = this.fsb;
        return (byte)i;
    }
    
    public int gQ()
    {
        return this.Uo;
    }
    
    public int dfY()
    {
        return this.lMU;
    }
    
    public cGR[] dsy()
    {
        return this.mol;
    }
    
    public void reset()
    {
        this.mok = 0;
        this.UA = 0;
        this.bQK = 0;
        this.fsb = (byte)0;
        this.Uo = 0;
        this.lMU = 0;
        this.mol = null;
    }
    
    public void a(ceb a)
    {
        this.mok = a.getInt();
        this.UA = a.getInt();
        this.bQK = a.getInt();
        int i = a.get();
        this.fsb = (byte)i;
        this.Uo = a.getInt();
        this.lMU = a.getInt();
        int i0 = a.getInt();
        this.mol = new cGR[i0];
        int i1 = 0;
        while(i1 < i0)
        {
            this.mol[i1] = new cGR();
            this.mol[i1].a(a);
            i1 = i1 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eDB.getId();
    }
}